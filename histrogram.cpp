
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

Mat calc_histogram(std::vector<DataDictionary> dictLst)
{
    Mat hist;
    hist = Mat::zeros(dictLst.size(), 1, CV_32F);
    // scr.convertTo(scr, CV_32F);
    double value = 0;
    for (int i = 0; i < dictLst.size(); i++)
    {
        // for (int j = 0; j < scr.cols; j++)
        // {

        // (b0 + b1 * normStaffs + b2 * normSpace + b3 * dataDict[idx].GetCarParking() + b4 * normDemographic +
        //      b6 * ((double)(dataDict[idx].Population_40().population / totalPopulation)) + b7 * ((double)(dataDict[idx].Population_30().population / totalPopulation)) + b8 * ((double)(dataDict[idx].Population_20().population / totalPopulation)) +
        //      b9 * ((double)(dataDict[idx].Population_10().population / totalPopulation)) + b10 * normClearence + b11 * normCompetition + b12 * normCompeteNum);

        // double normDemographic = (double)(dataDict[idx].GetDemographicScore() - MinMax[DEMOGRAPHIC_SCORE][0]) / (double)(MinMax[DEMOGRAPHIC_SCORE][1] - MinMax[DEMOGRAPHIC_SCORE][0]);
        //         double normCompetition = -(double)(dataDict[idx].CompetitionScore() - MinMax[COMPETITION_SCORE][0]) / (double)(MinMax[COMPETITION_SCORE][1] - MinMax[COMPETITION_SCORE][0]);
        //         double normSpace = (double)(dataDict[idx].GetSpace() - MinMax[SPACE][0]) / (double)(MinMax[SPACE][1] - MinMax[SPACE][0]);
        //         double normClearence = (double)(dataDict[idx].ClearenceSpace() - MinMax[CLEARENCE_SPACE][0]) / (double)(MinMax[CLEARENCE_SPACE][1] - MinMax[CLEARENCE_SPACE][0]);
        //         double normStaffs = (double)(dataDict[idx].GetStaffNumbers() - MinMax[STAFF_NUMBERS][0]) / (double)(MinMax[STAFF_NUMBERS][1] - MinMax[STAFF_NUMBERS][0]);
        //         double normCompeteNum = -(double)(dataDict[idx].CompetitionNumber() - MinMax[COMPETITION_NUM][0]) / (double)(MinMax[COMPETITION_NUM][1] - MinMax[COMPETITION_NUM][0]);

        float b0 = (float)dictLst[i].GetStaffNumbers();
        float b1 = (float)dictLst[i].GetSpace();
        float b2 = (float)dictLst[i].GetCarParking();
        float b3 = (float)dictLst[i].GetDemographicScore();
        float b4 = (float)dictLst[i].Population_40().population;
        float b5 = (float)dictLst[i].Population_30().population;
        float b6 = (float)dictLst[i].Population_20().population;
        float b7 = (float)dictLst[i].Population_10().population;
        float b8 = (float)dictLst[i].ClearenceSpace();
        float b9 = (float)dictLst[i].GetStaffNumbers();
        float b10 = (float)dictLst[i].CompetitionNumber();
        float b11 = (float)dictLst[i].CompetitionNumber();
        std::cout << hist.at<float>(b0) << std::endl;

        // value = scr.at<float>(i, j);
        hist.at<float>(i) = b0;  //hist.at<float>(b0);
        hist.at<float>(i) = b1;  //hist.at<float>(b1);
        hist.at<float>(i) = b2;  //hist.at<float>(b2);
        hist.at<float>(i) = b3;  //hist.at<float>(b3);
        hist.at<float>(i) = b4;  //hist.at<float>(b4);
        hist.at<float>(i) = b5;  //hist.at<float>(b5);
        hist.at<float>(i) = b6;  //hist.at<float>(b6);
        hist.at<float>(i) = b7;  //hist.at<float>(b7);
        hist.at<float>(i) = b8;  //hist.at<float>(b8);
        hist.at<float>(i) = b9;  //hist.at<float>(b9);
        hist.at<float>(i) = b10; //hist.at<float>(b10);
        hist.at<float>(i) = b11; //hist.at<float>(b11);

        //}
    }
    return hist;
}

void plot_histogram(Mat histogram)
{
    Mat histogram_image(400, 512, CV_8UC3, Scalar(0, 0, 0));
    Mat normalized_histogram;
    normalize(histogram, normalized_histogram, 0, 400, NORM_MINMAX, -1, Mat());

    for (int i = 0; i < 256; i++)
    {
        rectangle(histogram_image, Point(2 * i, histogram_image.rows - normalized_histogram.at<float>(i)), Point(2 * (i + 1), histogram_image.rows), Scalar(255, 0, 0));
    }

    namedWindow("Histogram", WINDOW_NORMAL);
    imshow("Histogram", histogram_image);
}

void histo(std::vector<DataDictionary> dictLst)
{

    Mat img;
    // img = imread("airship.jpg", 0);
    // Histogram H1;
    Mat hist = calc_histogram(dictLst);
    // H1.plot_histogram(hist);
    plot_histogram(hist);
    waitKey(0);
}