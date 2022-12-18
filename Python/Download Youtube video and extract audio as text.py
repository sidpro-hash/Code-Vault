from pytube import YouTube
from pytube.cli import on_progress
import pytube.request
import random
import time
import traceback
import os
 
from pydub import AudioSegment
from pydub.utils import make_chunks

import speech_recognition as sr 
import moviepy.editor as mp



pytube.request.default_range_size = 500000
def typewrite(num1,num2,text):
    for c in text:
        r = random.uniform(num1,num2)
        time.sleep(r)
        print(c,end='',flush=True)


def completed(a,b):
    completed = '\nDownload Completed!\n'
    size = 'File Size ' + str(stream.filesize/1000000) + ' Mb\n'
    title = 'Title: ' + stream.title + '\n'
    desc = 'Description: ' + yt.description + '\n'
    author = 'Author: ' + yt.author + '\n'
    length = 'Video Length ' + str(yt.length) + ' Seconds\n'

    txt_list = [completed,size,title,desc,author,length]

    for t in txt_list:
        if len(t) > 50:
            typewrite(.02,.03,t)
        else:
            typewrite(.05,.1,t)

        print('-' * 60)

url = input('\n Please Enter the URL: ')

try:
    # step 1 Download video
    yt = YouTube(url,on_progress_callback=on_progress,on_complete_callback=completed)
    stream = yt.streams.filter(progressive=True,file_extension='mp4').get_highest_resolution()
    typewrite(.05,.1,'Download is starting...\n')
    path = stream.download()
    parent = path[:path.rindex('\\')+1]
    audiofile = parent + stream.title + '.wav'
    transcript = parent + stream.title + '.txt'

    typewrite(.05,.1,'Extracting audio...\n')
    # step 2 Video to Audio conversion
    VidClip = mp.VideoFileClip(path) 
    VidClip.audio.write_audiofile(audiofile)

    # step 3 split audio into small chunks of 40s
    typewrite(.05,.1,'splitting audio into small chunks of 40s...\n')
    myaudio = AudioSegment.from_file(audiofile, "wav") 
    chunk_length_ms = 40000 # pydub calculates in millisec
    chunks = make_chunks(myaudio, chunk_length_ms) # Make chunks of sec
    final_result = ""
    typewrite(.05,.1,'Converting audio to text...\n')
    for i, chunk in enumerate(chunks):
        chunk_name = "chunk{0}.wav".format(i)
        print("exporting", chunk_name)
        chunk.export(chunk_name, format="wav")
        # Step 4: Speech recognition
        reco = sr.Recognizer()
        audio = sr.AudioFile(chunk_name)
        print("recognizing text from audio",chunk_name)
        try:
            with audio as source:
                audio_file = reco.record(source)
                result = reco.recognize_google(audio_file) # https://cloud.google.com/speech-to-text/quotas
                final_result+=" "+result
        except Exception:
            traceback.print_exc()
            final_result+="   skipped:"+chunk_name+"   "
        os.remove(chunk_name)

    # Step 5: Finally exporting the result 
    with open(transcript,mode ='w') as file: 
        file.write("Recognized Speech Text:\n") 
        file.write(final_result) 
        typewrite(.05,.1,'Extraction Completed!\n')
    
    
except Exception:
    traceback.print_exc()