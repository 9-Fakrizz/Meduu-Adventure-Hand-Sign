#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <conio.h>

using namespace cv;
using namespace std;

int capture(Mat img) {
	for (int i = 1; i < 4; i++) {
		putText(img,to_string(i), Point(100, 100), FONT_HERSHEY_DUPLEX, 5, Scalar(255, 255, 255), 1);
	}
	
}

void main() {

	int result;

	
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
			capture(img);
			cout << "Image captured" << endl;
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