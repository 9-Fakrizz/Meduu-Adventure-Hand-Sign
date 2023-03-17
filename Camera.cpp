#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <conio.h>
#include <unordered_map>
#include <time.h>
#include <cstdlib>

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

	srand(time(0));

	int i = 0 ;
	int freq;
	int total_state;
	string action=" ";

	vector<int> state;
	vector<int> result;
	vector<int> attack;
	vector<int> defend;//prototype not use yet
	vector<int> result2;
	

	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");



	while (true) {
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);

		if (attack.size() == 0 ) {
			for (int i = 0; i < 3; i++) {
				attack.push_back(rand()%3+1);
			}
		}
		
		total_state = most_frequent(state);
		freq = most_frequent(result);
		
		if (state.size() == 3) state.clear();

		if (result2.size() == 3) {
			result2.clear();
		}
		else result2.push_back(freq);


		if (attack.size() != 0 ) {
			if (attack.size() == result2.size() && attack.size()!=0) {
		
				for (int i = 0; i < attack.size(); i++) {
					if (result2[i] == attack[i]) state.push_back(1);
					else state.push_back(0);
				}
				
			}
	
		}

		
		if (total_state == 1) {
			//action = "ATTACK";
			putText(img, "ATTACK", Point(125, 300), FONT_HERSHEY_DUPLEX, 3, Scalar(255, 255, 255), 1);
			attack.clear();
			result2.clear();
			total_state = 0;
		}
		else {
			//putText(img, "MISS", Point(125, 300), FONT_HERSHEY_DUPLEX, 3, Scalar(255, 255, 255), 1);
		}
		
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

		if (result.size() > 15) {
			result.clear();

		}
		

		cout << faces.size() << endl;

		rectangle(img, Point(400, 0), Point(700, 70), Scalar(0, 80, 225), FILLED);
		putText(img, "Attack Code : [ " + to_string(attack[0]) + to_string(attack[1]) + to_string(attack[2]) + " ]", Point(220, 120), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 0), 1);
		
		putText(img, "Your Code : [ " + to_string(result2[0]) + to_string(result2[1]) + to_string(result2[2]) + " ]", Point(220, 100), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 0), 1);
		
		rectangle(img, Point(250, 0), Point(500, 70), Scalar(50, 225, 255), FILLED);
		putText(img, "Result :  " + to_string(freq), Point(280, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 1);

		//putText(img, action, Point(300, 300), FONT_HERSHEY_DUPLEX, 3, Scalar(255, 255, 255), 1);
		
		rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED); //retangle about display behind text
		putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1); // text count face.size()

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3); //retangle around facess
		}
		
		
		
		imshow("Frame", img);
		waitKey(1);
	}


}