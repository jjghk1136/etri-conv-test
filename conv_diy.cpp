#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src,
               cv::Mat dst,
               cv::Mat kernel,
               int stride,
               int padding
               )
{
    int src_height = src.rows;
    int src_width = src.cols;

    int kernel_height = kernel.rows;
    int kernel_width = kernel.cols;

    int dst_height;
    int dst_width;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]

    // MAKE YOUR OWN CONVOLUTION PROCESS

       
//serching
dst_height = (src_height+2 * padding - kernel_height)/stride+1 ;
dst_width= (src_width+2 * padding - kernel_width)/stride+1;


//int dst=dst[dst_height-1][dst_width-1];


for (int j=0 ; j < src_height-kernel_height; j+=stride){
        for (int i=0 ; i < src_width-kernel_width ; i+=stride){
        
//kernel cal
	  for (int y=0 ; y< kernel_height ; y+=1){
 			for (int x=0 ; x< kernel_width ; x+=1){
 			    dst[j,i] = src[j+y,i+x] * kernel[y,x];
				}
			}
		}
	}		







	
    // if success
    return 0

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 2) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst; //매트릭스 구조체
    // Load an image
    src = cv::imread( "1212.jpg"  );//경로에 있는 이미지읽기
    if( !src.data )  { return -1; }

    // Make filter
    kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
                                                                                
    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
