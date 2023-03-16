#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <conio.h>
#include <unordered_map>

using namespace cv;
using namespace std;

int most_frequent(vector<int> arr) {
	unordered_map<int, int> freq;
	int max_count = 0, max_num = 0;

	for (int i = 0; i < arr.size(); i++) {
		int num = arr[i];
		if (freq.count(num) == 0) {
			freq[num] = 1;
		}
		else {
			freq[num]++;
		}

		if (freq[num] > max_count) {
			max_count = freq[num];
			max_num = num;
		}
	}

	return max_num;
}

void main() {


	int i = 0 ;
	int freq;
	vector<int> result;
	
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");



	while (true) {
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);

		
		freq = most_frequent(result);
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
			result.push_back(faces.size());
			i++;
		}

		if (result.size() > 15) result.clear();
		

		cout << faces.size() << endl;

		rectangle(img, Point(250, 0), Point(500, 70), Scalar(50, 225, 255), FILLED);
		putText(img, "Result :  " + to_string(freq), Point(280, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 1);

		rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED); //retangle about display behind text
		putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1); // text count face.size()

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3); //retangle around facess
		}
		
		
		
		imshow("Frame", img);
		waitKey(1);
	}


}