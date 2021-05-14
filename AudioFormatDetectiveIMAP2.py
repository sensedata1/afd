#
# Shebang for Studio Mac Pro #
import datetime
import logging
import os
import shutil
import subprocess
import time
from pathlib import Path
from zipfile import ZipFile
import audiotools
import eyed3
import speech_recognition as sr
from colors import *
from pydub import AudioSegment
from watchdog.events import LoggingEventHandler
from watchdog.observers import Observer
from multiprocessing import Process, Pool
import multiprocessing
import sys

# Let's define some colours
black = lambda text: '\033[0;30m' + text + '\033[0m'
red = lambda text: '\033[0;31m' + text + '\033[0m'
green = lambda text: '\033[0;32m' + text + '\033[0m'
yellow = lambda text: '\033[0;33m' + text + '\033[0m'
blue = lambda text: '\033[0;36m' + text + '\033[0m'
magenta = lambda text: '\033[0;35m' + text + '\033[0m'
cyan = lambda text: '\033[0;36m' + text + '\033[0m'
white = lambda text: '\033[0;37m' + text + '\033[0m'

# create global instance of speech_recognition
r = sr.Recognizer()
proceed = 1


# Set up a "clear" with cross platform compatibility with Windows
def clear():
    os.system('cls' if os.name == 'nt' else 'clear')


def unzip():
    os.chdir(AJDownloadsFolder)
    cwd = os.getcwd()
    # Look for zip files and unzip then remove
    for directory, subdirectories, files in os.walk(cwd):
        for file in files:
            # print(file) Debugging output
            if file.lower().endswith((".zip",)) and os.path.isfile(os.path.join(directory, file)):
                currentZipFile = os.path.join(directory, file)
                zipFolderName = os.path.splitext(currentZipFile)[0]
                # print(file)
                try:
                    with ZipFile(currentZipFile, 'r') as zipArchive:
                        try:
                            zipArchive.extractall(zipFolderName)
                            # print('Extracting...')
                            # print('Done!')
                            # print("")
                            os.remove(currentZipFile)
                        except Exception as e:
                            # print("zip file corrupt")
                            print("Zip already extracted?")
                            print(e)

                        hiddenFolder = (os.path.join(zipFolderName, "__MACOSX"))
                        if os.path.isdir(hiddenFolder):
                            try:
                                shutil.rmtree(hiddenFolder)
                                print("Found and removed __MACOSX hidden folder...")
                                # print("")
                            except:
                                print("unable to remove __MACOSX hidden folder...")
                    return True
                except Exception as e:
                    print(e)
                    print("Unzip failed, zipfile may be corrupt")


def process_audio_files(currentFile):
    eyed3.log.setLevel("ERROR")
    curPath, file = os.path.split(currentFile)

    if currentFile.lower().endswith((".mp3",)) and not currentFile.startswith(".") \
            and os.path.isfile(currentFile):
        try:
            mp3File = eyed3.load(currentFile)
        except:
            mp3File = "Could not load MP3"
        try:
            bitRate = mp3File.info.bit_rate
        except:
            bitRate = ""
        try:
            sampleRate = mp3File.info.sample_freq
        except:
            sampleRate = "Samplerate Unsupported"
        try:
            channels = str(mp3File.info.mode)
        except:
            channels = ""
        try:
            durationSecs = mp3File.info.time_secs
            duration = str(datetime.timedelta(seconds=durationSecs))
        except:
            duration = "***"
        try:
            bits = (audiotools.open(currentFile).bits_per_sample())
        except Exception as e:
            bits = "  "

        # convert mp3 to wav for voice recognition
        home = str(Path.home())
        src = currentFile
        dst = os.path.join(home, "tempWav.wav")
        sound = AudioSegment.from_mp3(src)  # [10000:]
        sound.export(os.path.join(home, "tempWav.wav"), format="wav")
        # Do watermark detection with voice recognition only on testWav.wav
        srVoiceTestWav = sr.AudioFile(dst)
        try:
            with srVoiceTestWav as source:

                audio = r.record(source, duration=10)

                recognisedSpeech = str((r.recognize_google(audio)))
                if "audio" or "jungle" or "audiojungle" in recognisedSpeech:
                    ch = red("WM")
                if "jungle" in recognisedSpeech:
                    ch = red("WM")
                if "audi" in recognisedSpeech:
                    ch = red("WM")
                else:
                    ch = "  "
        except Exception as e:
            ch = "  "
            wm = "nowm"
            recognisedSpeech = ''

        if channels.lower() == "joint stereo" or "stereo":
            channels = 2
        try:
            rate = int(bitRate[1])
        except:
            rate = "err"
        vbrTrueFalse = "  "
        if sampleRate == 44100 and channels == 2 and 325 > rate > 315:  # and wm != "wmd":
            errorMp3 = green(" [ok]")
        else:
            errorMp3 = red("[ERR]")
        ######################################################################################
        #           PRINT MP3 DATA                                                           #
        ######################################################################################
        print(errorMp3, sampleRate, bits, channels, ch, vbrTrueFalse, rate, duration[3:-7], file, red(recognisedSpeech))
    # Look for wav files and evaluate
    if currentFile.lower().endswith((".wav",)) and not currentFile.startswith(".") \
            and os.path.isfile(currentFile):
        try:
            sampleRate = (audiotools.open(currentFile).sample_rate())
            ch = "ch"
            gap = "      "
        except:
            sampleRate = "BitDepth Unsupported"
            gap = ""
            ch = ""
        try:
            bits = (audiotools.open(currentFile).bits_per_sample())
        except:
            bits = ""
        try:
            channels = int(audiotools.open(currentFile).channels())
        except:
            channels = ""
        try:
            durationSecsWav = int(audiotools.open(currentFile).seconds_length())
            duration = str(datetime.timedelta(seconds=durationSecsWav))
        except:
            duration = "****"
        srVoiceTestWav = sr.AudioFile(currentFile)
        try:
            with srVoiceTestWav as source:
                audio = r.record(source, duration=10)
                # Alternative speech recognition #
                # recognisedSpeech = str((r.recognize_wit(audio,
                # key='RGAIIA26NIKLTR5PFPTMZM5MEHUC4MI3', show_all=False)))
                recognisedSpeech = str((r.recognize_google(audio, )))

                if "audio" in recognisedSpeech:
                    ch = red("WM")
                if "jungle" in recognisedSpeech:
                    ch = red("WM")
                if "audi" in recognisedSpeech:
                    ch = red("WM")
                else:
                    ch = "  "
        except Exception as e:

            ch = "  "
            wm = "nowm"
            recognisedSpeech = ''
        if sampleRate == 44100 and bits == 16 and channels == 2:
            errorWav = green(" [ok]")
        else:
            errorWav = red("[ERR]")
            LACout = ""
        ######################################################################################
        #           PRINT WAV DATA                                                           #
        ######################################################################################
        print(errorWav, sampleRate, bits, channels, ch, gap, duration[3:], file, red(recognisedSpeech))
    # If any other audio file types are present mark as [ERR]
    if file.lower().endswith((".aac", ".aiff", ".aif", ".flac", ".m4a", ".m4p")) \
            and os.path.isfile(currentFile):
        try:
            sampleRate = (audiotools.open(currentFile).sample_rate())
        except:
            sampleRate = "Bitdepth Unsupported"
        try:
            bits = (audiotools.open(currentFile).bits_per_sample())
        except:
            bits = " "
        try:
            channels = int(audiotools.open(currentFile).channels())
        except:
            channels = " "
        errorWav = red("[ERR]")
        ch = ""
        print(errorWav, sampleRate, bits, channels, ch, "         ", file)


# Watch folder and run main function when a file is downloaded into folder


# class Event(LoggingEventHandler):
#     def on_moved(self, event):
#         # print(event)
#         if os.path.basename(os.path.normpath(event.src_path)).endswith(".crdownload"):
#             # print(event)
#             os.chdir(AJDownloadsFolder)
#             cwd = os.getcwd()
#             unzip()
#             clear()
#             print('\n' * 50)
#             print("analysing...")
#             time.sleep(1)
#             currentFileList = []
#
#             with Pool(processes=multiprocessing.cpu_count()) as pool:
#                 for directory, subdirectories, files in os.walk(cwd):
#                     for file in files:
#                         tempCurrentFile = os.path.join(directory, file)
#                         if tempCurrentFile.lower().endswith \
#                                     ((".mp3", ".aac",
#                                       ".aiff", ".aif", ".flac", ".m4a",
#                                       ".m4p", ".wav",)) and not tempCurrentFile.startswith(".") \
#                                 and os.path.isfile(tempCurrentFile):
#                             currentFileList.append(tempCurrentFile)
#
#                 for currentFile in currentFileList:
#                     pool.imap_unordered(process_audio_files, (currentFile,))
#
#                 pool.close()
#                 pool.join()
#                 print("All done!")


# Delete old files and folders
class Event(LoggingEventHandler):
    def on_moved(self, event):
        # print(event)
        os.chdir(AJDownloadsFolder)
        cwd = os.getcwd()
        currentFileList = []
        currentDirList = []
        if os.path.basename(os.path.normpath(event.src_path)).endswith(".crdownload"):
            for directory, subdirectories, files in os.walk(cwd):
                for file in files:
                    tempCurrentFile = os.path.join(directory, file)
                    if not tempCurrentFile.lower().endswith(".crdownload") \
                            and os.path.isfile(tempCurrentFile):
                        currentFileList.append(tempCurrentFile)
                for subdirectory in subdirectories:
                    currentDirList.append(subdirectory)

            for currentFile in currentFileList:
                if not currentFile.lower().endswith('.zip'):
                    os.remove(currentFile)
            for currentDir in currentDirList:
                if os.path.exists(currentDir) and os.path.isdir(currentDir):
                    shutil.rmtree(currentDir)


def os_walk():
    # print(event)
    os.chdir(AJDownloadsFolder)
    cwd = os.getcwd()
    if unzip():

        clear()
        print('\n' * 50)
        print("analysing...")
        time.sleep(1)
        currentFileList = []
        start = time.time()

        with Pool(processes=multiprocessing.cpu_count()) as pool:
            for directory, subdirectories, files in os.walk(cwd):
                for file in files:
                    tempCurrentFile = os.path.join(directory, file)
                    if tempCurrentFile.lower().endswith \
                                ((".mp3", ".aac",
                                  ".aiff", ".aif", ".flac", ".m4a",
                                  ".m4p", ".wav",)) and not tempCurrentFile.startswith(".") \
                            and os.path.isfile(tempCurrentFile):
                        currentFileList.append(tempCurrentFile)

            for currentFile in currentFileList:
                pool.imap_unordered(process_audio_files, (currentFile,))

            pool.close()
            pool.join()
            end = time.time()
            pTime = str("{:.2f}".format(end - start))
            print('processed ' + str(len(currentFileList)) + ' files in ' + pTime + 's')
            # print("All done!")


if __name__ == "__main__":
    multiprocessing.set_start_method('spawn')
    # Suppress warnings from eyeD3
    eyed3.log.setLevel("ERROR")
    # Get AJ Downloads folder from user input
    userFolder = input("Drag your AJ downloads folder here and press enter...")
    # Format the user input
    tempVar = userFolder.replace("\\", "")
    tempVar2 = tempVar.rstrip()
    AJDownloadsFolder = os.path.abspath(tempVar2)
    os.chdir(AJDownloadsFolder)
    print("Downloads folder = " + AJDownloadsFolder)
    print("")
    print("Monitoring " + AJDownloadsFolder + "...")

    # logging.basicConfig(level=logging.INFO,
    #                     format='%(asctime)s - %(message)s',
    #                     datefmt='%Y-%m-%d %H:%M:%S')
    path = sys.argv[1] if len(sys.argv) > 1 else '.'
    event_handler = Event()
    observer = Observer()
    observer.schedule(event_handler, path, recursive=False)
    observer.start()
    try:
        while True:
            time.sleep(1)
            os_walk()
    except KeyboardInterrupt:
        print("Interrupt received, stopping...")
    finally:
        exit()

        observer.stop()
    observer.join()
