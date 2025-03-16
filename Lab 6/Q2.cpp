#include<iostream>
using namespace std;

class MediaFile{
	protected:
		string filePath;
		int size;
		
	public:
		MediaFile(string f, int s){
			filePath = f;
			size = s;
		}
		virtual ~MediaFile() { }
		virtual void play(){
			cout << "Playing " << filePath << endl;
		}
		virtual void stop(){
			cout << "Stopped " << filePath << endl;
		}
};

class VisualMedia : virtual public MediaFile {
	protected:
        int resWidth;
        int resHeight;
        
	public:
		VisualMedia(string f, int s, int width, int height) : MediaFile(f, s){
			resWidth = width;
			resHeight = height;
		}
		void displayRes() const {
            cout << "Resolution: " << resWidth << " x " << resHeight << endl;
        }
};

class AudioMedia : virtual public MediaFile{
	protected:
        int sampleRate;
	public:
		AudioMedia(string f, int s, int rate) : MediaFile(f, s){
			sampleRate = rate;
		}
		void displayRate() const{
            cout << "Sample Rate: " << sampleRate << " Hz" << endl;
        }
};

class VideoFile : public VisualMedia, public AudioMedia{
	public:
		VideoFile(string f,int s, int w, int h, int r) : MediaFile(f, s), VisualMedia(f, s, w, h), AudioMedia(f, s, r) { }
		
		void play() override{   // This function overrides the Parent Class Play function by adding additional features.
            cout << "Playing video file: " << filePath << endl;
            displayRes();
            displayRate();
        }
        void stop() override {
            cout << "Stopping video file: " << filePath << endl;
        }
};

class ImageFile : public VisualMedia {
	public:
	    ImageFile(string f, int s, int w, int h) 
	        : MediaFile(f, s), VisualMedia(f, s, w, h) {}
	    
	    void play() override {
	        cout << "Displaying image file: " << filePath << endl;
	        displayRes();
	    }
};

class AudioFile : public AudioMedia {
	public:
	    AudioFile(string f, int s, int r) 
	        : MediaFile(f, s), AudioMedia(f, s, r) {}
	    
	    void play() override {
	        cout << "Playing audio file: " << filePath << endl;
	        displayRate();
	    }
};
int main(){
	MediaFile* media1 = new VideoFile("video.mp4", 100, 1920, 1080, 44100);
    MediaFile* media2 = new ImageFile("picture.jpg", 50, 1280, 720);
    MediaFile* media3 = new AudioFile("song.mp3", 30, 44100);
    
    media1->play();
    cout << endl;
    media2->play();
    cout << endl;
	media3->play();
    cout << endl;
    
    media1->stop();
    cout << endl;
    media2->stop();
    cout << endl;
    media3->stop();
    
    delete media1;
    delete media2;
    delete media3;
    
}
