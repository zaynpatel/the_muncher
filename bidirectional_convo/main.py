import stt
import tts

def main():
    spoken_text = stt.capture_and_transcribe()
    tts.get_gpt4_response(spoken_text)

if __name__ == "__main__":
    main()