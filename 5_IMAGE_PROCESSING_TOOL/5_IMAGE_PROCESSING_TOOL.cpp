#include <iostream>
#include <opencv2/opencv.h>

using namespace std;
using namespace cv;

int main() {
    Mat image;
    int choice;

    cout << "Image Processing Tool" << endl;
    cout << "1. Load Image" << endl;
    cout << "2. Display Image" << endl;
    cout << "3. Apply Grayscale Filter" << endl;
    cout << "4. Apply Blur Filter" << endl;
    cout << "5. Apply Sharpen Filter" << endl;
    cout << "6. Adjust Colors (Brightness/Contrast)" << endl;
    cout << "7. Crop Image" << endl;
    cout << "8. Resize Image" << endl;
    cout << "9. Save Image" << endl;
    cout << "0. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Load Image
                cout << "Enter image file path: ";
                cin.ignore();
                string imagePath;
                getline(cin, imagePath);
                image = imread(imagePath);
                if (image.empty()) {
                    cout << "Error: Unable to load the image." << endl;
                }
                break;

            case 2: // Display Image
                if (!image.empty()) {
                    namedWindow("Loaded Image");
                    imshow("Loaded Image", image);
                    waitKey(0);
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 3: // Grayscale Filter
                if (!image.empty()) {
                    cvtColor(image, image, COLOR_BGR2GRAY);
                    cout << "Grayscale filter applied." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 4: // Blur Filter
                if (!image.empty()) {
                    GaussianBlur(image, image, Size(5, 5), 0);
                    cout << "Blur filter applied." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 5: // Sharpen Filter
                if (!image.empty()) {
                    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
                    filter2D(image, image, image.depth(), kernel);
                    cout << "Sharpen filter applied." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 6: // Adjust Colors (Brightness/Contrast)
                if (!image.empty()) {
                    double alpha, beta;
                    cout << "Enter brightness adjustment (1.0 is default): ";
                    cin >> alpha;
                    cout << "Enter contrast adjustment (1.0 is default): ";
                    cin >> beta;
                    image.convertTo(image, -1, alpha, beta);
                    cout << "Colors adjusted." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 7: // Crop Image
                if (!image.empty()) {
                    int x, y, width, height;
                    cout << "Enter x-coordinate of top-left corner: ";
                    cin >> x;
                    cout << "Enter y-coordinate of top-left corner: ";
                    cin >> y;
                    cout << "Enter width: ";
                    cin >> width;
                    cout << "Enter height: ";
                    cin >> height;
                    Rect roi(x, y, width, height);
                    image = image(roi);
                    cout << "Image cropped." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 8: // Resize Image
                if (!image.empty()) {
                    int newWidth, newHeight;
                    cout << "Enter new width: ";
                    cin >> newWidth;
                    cout << "Enter new height: ";
                    cin >> newHeight;
                    resize(image, image, Size(newWidth, newHeight));
                    cout << "Image resized." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 9: // Save Image
                if (!image.empty()) {
                    string outputPath;
                    cout << "Enter output file path: ";
                    cin.ignore();
                    getline(cin, outputPath);
                    imwrite(outputPath, image);
                    cout << "Image saved." << endl;
                } else {
                    cout << "Error: No image loaded." << endl;
                }
                break;

            case 0: // Exit
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
