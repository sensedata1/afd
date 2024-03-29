FROM python
COPY . /app
WORKDIR /app
RUN apt-get update && apt-get install -y apt-utils
RUN apt-get -y install libcdio-utils
RUN apt-get -y install python-pyaudio python3-pyaudio
RUN apt-get -y install vim
RUN apt-get -y install make
RUN apt-get -y install cron
RUN apt-get -y install python-setuptools
RUN apt-get -y install ffmpeg
RUN chmod a+x docker-build-script.sh && ./docker-build-script.sh
RUN mkdir /AJTEMP

CMD python AudioFormatDetectiveIMAP2CON.py