#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <conio.h>

using namespace cv;
using namespace std;

void main() {

	int result;
	int i = 0 ;

	
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");



	while (true) {
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);

		
		
		int key = waitKey(1);
		if (key == 'b') {
			i = 1;
			cout << "Image captured" << endl;
		}
		if (i==51) i = 0;
		else if (i!=0 && i<40) {
			putText(img, to_string(i/10), Point(200, 350), FONT_HERSHEY_DUPLEX, 10, Scalar(255, 255, 255), 1);
			i++;
		}
		else if (i >= 40) {
			putText(img, "CHEESE", Point(125, 300), FONT_HERSHEY_DUPLEX, 3, Scalar(255, 255, 255), 1);
			i++;
		}


		cout << faces.size() << endl;

		rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED); //retangle about display behind text
		putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1); // text count face.size()

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3); //retangle around facess
		}
		
		
		
		imshow("Frame", img);
		waitKey(1);
	}


}