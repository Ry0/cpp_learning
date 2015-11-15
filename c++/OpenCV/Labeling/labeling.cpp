#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <vector>

int main( int argc, const char** argv )
{
    // グレースケールで画像読み込み
    cv::Mat src = cv::imread("../input.bmp", cv::IMREAD_GRAYSCALE);

    // 画像の読み込みに失敗したらエラー終了する
    if(src.empty())
    {
        std::cerr << "Failed to open image file." << std::endl;
        return -1;
    }

    // 二値化
    cv::Mat bin;
    cv::threshold(src, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    // ラベル用画像生成(※CV_32S or CV_16Uにする必要あり)
    cv::Mat labelImage(src.size(), CV_32S);

    // ラベリング実行．戻り値がラベル数．また，このサンプルでは8近傍でラベリングする．
    int nLabels = cv::connectedComponents(bin, labelImage, 8);
    // int nLabels = connectedComponentsWithStats(bin, labelImage, 8);

    // ラベリング結果の描画色を決定
    std::vector<cv::Vec3b> colors(nLabels);
    colors[0] = cv::Vec3b(0, 0, 0);
    for(int label = 1; label < nLabels; ++label)
    {
        colors[label] = cv::Vec3b((rand()&255), (rand()&255), (rand()&255));
    }

    // ラベリング結果の描画
    cv::Mat dst(src.size(), CV_8UC3);
    for(int y = 0; y < dst.rows; ++y)
    {
        for(int x = 0; x < dst.cols; ++x)
        {
            int label = labelImage.at<int>(y, x);
            cv::Vec3b &pixel = dst.at<cv::Vec3b>(y, x);
            pixel = colors[label];
        }
    }
    cv::namedWindow("Source", cv::WINDOW_AUTOSIZE );
    cv::imshow("Source", src );
    cv::namedWindow( "Connected Components", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Connected Components", dst );

    cv::waitKey(0);
    return 0;
}