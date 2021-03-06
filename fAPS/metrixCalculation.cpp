#include "StdAfx.h"
#include "metrixCalculation.h"
#include <stdio.h>

#include <cv.h>   
#include "highgui.h"   
#include <vector>   
#include <math.h> 
#include <iostream>

/*!
Matrix Multiplication
\param a an float of double pointer
\param b as float of dounle pointer
\return matrix as float
*/


float **metrixCalculation::MatrixMultiplication(float **a, float **b){



	float **c= new float*[3];

	for(int i=0; i<3;i++)
	{
		c[i]= new float[3];
	}

	int i , j , k;

	for( i = 0 ; i < 3 ; i++)
		for( j = 0 ; j < 3 ; j++)
		{
			c[i][j] = 0;
			for( k = 0 ;k < 3 ; k++)
				c[i][j] += a[i][k]*b[k][j];
		}


		return c;
}

/*!
Matrix inversion
\param A an float of double pointer
\param order as int
\return matrix as float
*/
float **metrixCalculation::MatrixInversion(float **A, int order)
{


	float **Y= new float*[3];

	for(int i=0; i<3;i++)
	{
		Y[i]= new float[3];
	}

	// get the determinant of a
	double det = 1.0/CalcDeterminant(A,order);

	// memory allocation
	float *temp = new float[(order-1)*(order-1)];
	float **minor = new float*[order-1];
	for(int i=0;i<order-1;i++)
		minor[i] = temp+(i*(order-1));

	for(int j=0;j<order;j++)
	{
		for(int i=0;i<order;i++)
		{
			// get the co-factor (matrix) of A(j,i)
			GetMinor(A,minor,j,i,order);
			Y[i][j] = det*CalcDeterminant(minor,order-1);
			if( (i+j)%2 == 1)
				Y[i][j] = -Y[i][j];
		}
	}

	// release memory
	//delete [] minor[0];
	delete [] temp;
	delete [] minor;
	return Y;
}


/*!
calculate the cofactor of element (row,col)
\param src an float of double pointer
\param dest as float of dounle pointer
\param row as int-no of rows
\param col as int- no of columns
\param order as int
\return int
*/

int metrixCalculation::GetMinor(float **src, float **dest, int row, int col, int order)
{
	// indicate which col and row is being copied to dest
	int colCount=0,rowCount=0;

	for(int i = 0; i < order; i++ )
	{
		if( i != row )
		{
			colCount = 0;
			for(int j = 0; j < order; j++ )
			{
				// when j is not the element
				if( j != col )
				{
					dest[rowCount][colCount] = src[i][j];
					colCount++;
				}
			}
			rowCount++;
		}
	}

	return 1;
}

/*!
 Calculate the determinant recursively.
\param mat an float of double pointer
\param order as int
\return as double
*/

double metrixCalculation::CalcDeterminant( float **mat, int order)
{
	// order must be >= 0
	// stop the recursion when matrix is a single element
	if( order == 1 )
		return mat[0][0];

	// the determinant value
	float det = 0;

	// allocate the cofactor matrix
	float **minor;
	minor = new float*[order-1];
	for(int i=0;i<order-1;i++)
		minor[i] = new float[order-1];

	for(int i = 0; i < order; i++ )
	{
		// get minor of element (0,i)
		GetMinor( mat, minor, 0, i , order);
		// the recusion is here!

		det += (i%2==1?-1.0:1.0) * mat[0][i] * CalcDeterminant(minor,order-1);
	}

	for(int i=0;i<order-1;i++)
		delete [] minor[i];
	delete [] minor;

	return det;
}


/*!
Calculate the determinant recursively.
\return float
*/
float **metrixCalculation::WrapFuction(){
	int trg_img_cordinate_x[19]={65,80,80,102,132,147,149,165,116,101,132,88,119,117,144,33,199,117,117};
	int trg_img_cordinate_y[19]={127,117,131,127,127,113,130,124,121,171,169,201,193,210,201,142,142,102,253};
	int db_img_cordinate_x[19]={62,79,80,104,136,156,157,173,120,99,144,87,120,120,148,35,196,119,117};
	int db_img_cordinate_y[19]={121,111,130,127,124,110,129,120,112,171,172,202,191,215,198,136,140,88,256};

	//float **wrapMetrix;

	float **wrapMetrix= new float*[3]; //assgin 1st dimention
	for(int i=0; i<3;i++)
	{
		wrapMetrix[i]= new float[3];
	}
	//float **QPt;
	//float **PPt;
	float **QPt= new float*[3]; //assgin 1st dimention
	for(int i=0; i<3;i++)
	{
		QPt[i]= new float[3];
	}



	float **PPt= new float*[3];

	for(int i=0; i<3;i++)
	{
		PPt[i]= new float[3];
	}

	float **PPt_inv=new float*[3];
	for(int i=0; i<3;i++)
	{
		PPt_inv[i]= new float[3];
	}


	QPt[0][0]=0.0;
	QPt[0][1]=0.0;
	QPt[0][2]=0.0;
	QPt[1][0]=0.0;
	QPt[1][1]=0.0;
	QPt[1][2]=0.0;
	QPt[2][0]=0.0;
	QPt[2][1]=0.0;
	QPt[2][2]=19.0;

	PPt[0][0]=0.0;
	PPt[0][1]=0.0;
	PPt[0][2]=0.0;
	PPt[1][0]=0.0;
	PPt[1][1]=0.0;
	PPt[1][2]=0.0;
	PPt[2][0]=0.0;
	PPt[2][1]=0.0;
	PPt[2][2]=19.0;



	for(int i=0; i<19;i++){

		QPt[0][0]=QPt[0][0] + trg_img_cordinate_x[i]*db_img_cordinate_x[i];
		QPt[0][1]=QPt[0][1] + trg_img_cordinate_x[i]*db_img_cordinate_y[i];
		QPt[0][2]=QPt[0][2] + trg_img_cordinate_x[i];
		QPt[1][0]=QPt[1][0] + trg_img_cordinate_y[i]*db_img_cordinate_x[i];
		QPt[1][1]=QPt[1][1] + trg_img_cordinate_y[i]*db_img_cordinate_y[i];
		QPt[1][2]=QPt[1][2] + trg_img_cordinate_y[i];
		QPt[2][0]=QPt[2][0] + db_img_cordinate_x[i];
		QPt[2][1]=QPt[2][1] + db_img_cordinate_y[i];
		//QPt[2][2]=19;


		PPt[0][0]=QPt[0][0] + db_img_cordinate_x[i]*db_img_cordinate_x[i];
		PPt[0][1]=QPt[0][1] + db_img_cordinate_x[i]*db_img_cordinate_y[i];
		PPt[0][2]=QPt[0][2] + db_img_cordinate_x[i];
		PPt[1][0]=QPt[1][0] + db_img_cordinate_x[i]*db_img_cordinate_y[i];
		PPt[1][1]=QPt[1][1] + db_img_cordinate_y[i]*db_img_cordinate_y[i];
		PPt[1][2]=QPt[1][2] + db_img_cordinate_y[i];
		PPt[2][0]=QPt[2][0] + db_img_cordinate_x[i];
		PPt[2][1]=QPt[2][1] + db_img_cordinate_y[i];
		//PPt[2][2]=19;


	}

	PPt_inv=MatrixInversion(PPt, 3);
	wrapMetrix=MatrixMultiplication(QPt, PPt_inv);
	return wrapMetrix;
}


/*!
Function takes OpenCV image as input and dumps its pixels to a file specified by filename in function arguments.
\param img as IplImage of input
\param filename as char pointer
\param mat as CvMat
\return int
*/
int metrixCalculation::WritePixelsToFile(IplImage *img,const char *filename,CvMat* mat)
{
	/*open a file in text mode with write permissions.*/
	FILE *file = fopen(filename, "wt");
	if(file==NULL)
	{
		/*If unable to open the specified file display error and return.*/
		perror("Unable to open specified file");
		return -1;
	}
	int i,j;
	CvScalar **s;
	CvSize size=cvGetSize(img);
	s= new CvScalar*[size.height];
	for(int i=0; i<size.height;i++)
	{
		s[i]= new CvScalar[size.width];
	}

	float **W=new float*[3];
	for(int i=0; i<3;i++)
	{
		W[i]= new float[3];
	}

	float **W_inv=new float*[3];
	for(int i=0; i<3;i++)
	{
		W_inv[i]= new float[3];
	}

	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			//a=cvmGet(points1, i, j);
			W[i][j]=cvmGet(mat, i, j);
		}
	}


	//W=WrapFuction(); //get the wrappin metrix
	W_inv=MatrixInversion(W, 3); // inverse the metrix
	//IplImage* img_out = cvCreateImage(size, 8,3 );
	IplImage *img_out= cvCloneImage(img);
	CvScalar ss;
	for(int i=300;i< size.height;i++)
	{
		for(int j=220;j< size.width;j++)
		{

			int X_pixel=j*W_inv[0][0]+i*W_inv[0][1]+ W_inv[0][2]; // reverce mapping value for x coordinate
			int Y_pixel=j*W_inv[1][0]+i*W_inv[1][1]+ W_inv[1][2];  // reverce mapping value for x coordinate
			//s[i][j]=cvGet2D(img,i,j); // get the (i,j) pixel value
			if(X_pixel<225 && Y_pixel<300){
				cvSet2D(img_out,i,j,cvGet2D(img,X_pixel,Y_pixel));


				//ss=cvGet2D(img,i,j); // get the (i,j) pixel value
				//printf("intensity=%f\n",s.val[0]);
				//ss.val[0]=111;
				//cvSet2D(img,i,j,ss);

			}
			// fprintf (file,"%f\t",s[i][j].val); // dump the (i,j) pixel value in file 
		}                         
		//fprintf(file,"\n");//write new line in file to seperate rows.         
	}




	//cvPerspectiveTransform( src, img_out, fundamental_matrix);


	/*release the file pointer.*/
	fclose(file);
	return 1;
} 

/*!
calculate fundermental matrix
\param src as ImplImage of input
\param dst as IplIamge as destination
*/

void metrixCalculation::CalFundermentalMatrix(IplImage *src,IplImage *dst)
{
	int point_count = 7;
	CvMat* points1;
	CvMat* points2;
	CvMat* status;
	CvMat* fundamental_matrix;
	//IplImage *src, *dst;
	float trg_img_cordinate_x[23]={0,0,240,240,61.0,80.0,80.0,102.0,132.0,147.0,149.0,165.0,116.0,101.0,132,88,119,117,144,33,199,117,117};
	float trg_img_cordinate_y[23]={0,320,0,320,127.0,117.0,131.0,127.0,127.0,113.0,130.0,124.0,121.0,171.0,169,201,193,210,201,142,142,102,253};
	float db_img_cordinate_x[23]={0,0,240,240,62.0,79.0,80.0,104.0,136.0,156.0,157.0,173.0,120.0,99.0,144.0,87,120,120,148,35,196,119,117};
	float db_img_cordinate_y[23]={0,320,0,320,121.0,111.0,130.0,127.0,124.0,110.0,129.0,120.0,112.0,171.0,172.0,202,191,215,198,136,140,88,256};

	//int db_img_cordinate_x[19]={65.0,80.0,80.0,102.0,132.0,147.0,149.0,165.0,116.0,101.0,132,88,119,117,144,33,199,117,117};
	//int db_img_cordinate_y[19]={127.0,117.0,131.0,127.0,127.0,113.0,130.0,124.0,121.0,171.0,169,201,193,210,201,142,142,102,253};


	points1 = cvCreateMat(2,point_count,CV_32FC1);
	points2 = cvCreateMat(2,point_count,CV_32FC1);
	status = cvCreateMat(1,point_count,CV_8UC1);


	/* Fill the points here ... */

	for( int i = 0; i < point_count; i++ )
	{

		cvmSet(points1, 0, i, trg_img_cordinate_x[i]);
		cvmSet(points1, 1, i, trg_img_cordinate_y[i]);
		cvmSet(points2, 0, i, db_img_cordinate_x[i]);
		cvmSet(points2, 1, i, db_img_cordinate_y[i]);
		/*
		points1->data.db[i*2] = trg_img_cordinate_x[i];
		points1->data.db[i*2+1] = trg_img_cordinate_y[i];
		points2->data.db[i*2] = db_img_cordinate_x[i];
		points2->data.db[i*2+1] = db_img_cordinate_y[i];
		*/
	}


	fundamental_matrix = cvCreateMat(3,3,CV_32FC1);
	//cvFindFundamentalMatrix( trg_img_cordinate_x,trg_img_cordinate_x,9,CV_FM_RANSAC,PPt_inv);
	int fm_count = cvFindFundamentalMat( points2,points1,fundamental_matrix,CV_FM_RANSAC);

	//cvFindHomography( points1,points2,fundamental_matrix,CV_FM_RANSAC,1.0);
	int a=0;
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			//a=cvmGet(points1, i, j);
			a=cvmGet(fundamental_matrix, i, j);
		}
	}

	CvMat* perspective_mat=cvCreateMat(3,3,CV_32FC1);;

	cvmSet(perspective_mat,0,0,2);
	cvmSet(perspective_mat,0,1,-4);
	cvmSet(perspective_mat,0,2,249);
	cvmSet(perspective_mat,1,0,9);
	cvmSet(perspective_mat,1,1,-11);
	cvmSet(perspective_mat,1,2,459);
	cvmSet(perspective_mat,2,0,0);
	cvmSet(perspective_mat,2,1,0);
	cvmSet(perspective_mat,2,2,1);

	IplImage *img_out= cvCloneImage(src);

	CvPoint2D32f srcTri[3], dstTri[3];
	// Compute warp matrix
	srcTri[0].x = 121;
	srcTri[0].y = 123;
	srcTri[1].x = 97;
	srcTri[1].y = 169;
	srcTri[2].x = 145;
	srcTri[2].y = 169;

	dstTri[0].x = 121;
	dstTri[0].y = 110;
	dstTri[1].x = 90;
	dstTri[1].y = 180;
	dstTri[2].x = 155;
	dstTri[2].y = 150;

	CvMat* affine_mat=cvCreateMat(2,3,CV_32FC1);
	cvGetAffineTransform( srcTri, dstTri, affine_mat );
	cvWarpAffine( src, img_out, affine_mat );

}