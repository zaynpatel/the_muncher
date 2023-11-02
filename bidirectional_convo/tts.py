# Text to speech is the side of GPT giving me an output using a custom voice
"""
Learnings:

- Had a few installation errors for pyttsx3, a `pip install pyttsx3` gives an error that pyobjc is not found. 
Even when running `pip install pyobjc` this error persists. My solution was running `pip install py3-tts` from:

-> This project (https://pypi.org/project/py3-tts/)
-> Thanks to this stack overflow (https://stackoverflow.com/questions/77197398/error-running-pyttsx3-code-on-os-x-nameerror-name-objc-is-not-defined)

"""
import pyttsx3
import openai
import stt

openai.api_key = ''

# Initialize the TTS engine
engine = pyttsx3.init()

# Set properties (optional)
engine.setProperty('rate', 175)  # Speed of speech
engine.setProperty('volume', 1)  # Volume (0.0 to 1.0)
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id) # relies on voices on the operating system. sounds robotic for now but maybe there's something better later. 

# Text to be spoken
def get_gpt4_response(text):
    model_engine = "text-davinci-003"
    response = openai.Completion.create(
        engine = model_engine, 
        prompt=text, 
        max_tokens = 100 # confirm this is max tokens per response 
    )
    responses = response.choices[0].text.strip() # prioritize highest response based on prob dist
    engine.say(responses) # want the output to be the top choice
    engine.runAndWait()
