#include <stdio.h>
#include <stdlib.h>

/* bitmap header */
typedef struct BitmapHeader {
  	unsigned char Type[2];
  	unsigned int Size;
	unsigned char Reserved[4];
  	unsigned int OffsetBits;
  	unsigned int InfoSize;
  	unsigned int Width;
  	unsigned int Height;
  	unsigned short Planes;
  	unsigned short BitPerPixel;
  	unsigned int Compression;
  	unsigned int ImageSize;
  	unsigned int XResolution;
  	unsigned int YResolution;
  	unsigned int Colors;
  	unsigned int ImportantColors;
} Header;


int ImageProcessing(const char *fileName_s, const char *fileName_d){
	FILE *fPointer_s = NULL;	// source file pointer
	FILE *fPointer_d = NULL;	// destination file pointer
	Header header;
	
	int x = 0, y = 0, i, j, k;
	int width = 0, height = 0;
	unsigned int fileSize;
	unsigned char *palette;
	unsigned char *img_s;	// stored source image data
	unsigned char *img_d;	// stored destination image data
	unsigned char R, G ,B;
	
	
	/* read file */
	fPointer_s = fopen(fileName_s, "rb");
	if(fPointer_s == NULL){
		printf("Can not open image : %s\n", fileName_s);
		return -1;
	}
	/* write file */
	fPointer_d = fopen(fileName_d, "wb");
	
	
	/* read header */
	fread(&header.Type, 2, 1, fPointer_s);
  	fread(&header.Size, 4, 1, fPointer_s);
  	fread(&header.Reserved, 4, 1, fPointer_s);	
  	fread(&header.OffsetBits, 4, 1, fPointer_s);
  	fread(&header.InfoSize, 4, 1, fPointer_s);
  	fread(&header.Width, 4, 1, fPointer_s);
  	fread(&header.Height, 4, 1, fPointer_s);
  	fread(&header.Planes, 2, 1, fPointer_s);
  	fread(&header.BitPerPixel, 2, 1, fPointer_s);
  	fread(&header.Compression, 4, 1, fPointer_s);
  	fread(&header.ImageSize, 4, 1, fPointer_s);
  	fread(&header.XResolution, 4, 1, fPointer_s);
  	fread(&header.YResolution, 4, 1, fPointer_s);
  	fread(&header.Colors, 4, 1, fPointer_s);
  	fread(&header.ImportantColors, 4, 1, fPointer_s);
  	
  	palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14);
  	fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fPointer_s);
  	
  	width = header.Width;
  	height = header.Height;
  	
  	
	/* malloc */
	/* array size = w * h * 3(r, g, b)*/
	img_s = (unsigned char *) malloc(header.ImageSize *3);
	img_d = (unsigned char *) malloc(header.ImageSize *3);
	fread(img_s, header.ImageSize, 1, fPointer_s);
	fclose(fPointer_s);
	
	/* processing -----------------------------------------------------------------------------------*/
	
	for(j = 0; j != height; j++){	// 第幾列  (橫向) 
		for(i = 0; i != width; i++){	// 第幾行  (直向) 
			
			B = *(img_s + 3 *(width *j + i) + 0);
			G = *(img_s + 3 *(width *j + i) + 1);
			R = *(img_s + 3 *(width *j + i) + 2);
			//  *(img_s + 3 * width *j + 3 * i + 2) 
			
			*(img_d + 3 *(width *j + i) + 0) = R * 0.229 + G * 0.587 + B * 0.144;
			*(img_d + 3 *(width *j + i) + 1) = R * 0.229 + G * 0.587 + B * 0.144;
			*(img_d + 3 *(width *j + i) + 2) = R * 0.229 + G * 0.587 + B * 0.144;
			
		}
	}
	
	/* processing -----------------------------------------------------------------------------------*/

	
	
	
	/* write header */
	fwrite(&header.Type, 2, 1, fPointer_d);
	fwrite(&header.Size, 4, 1, fPointer_d);
  	fwrite(&header.Reserved, 4, 1, fPointer_d);	
  	fwrite(&header.OffsetBits, 4, 1, fPointer_d);
  	fwrite(&header.InfoSize, 4, 1, fPointer_d);
  	fwrite(&header.Width, 4, 1, fPointer_d);
  	fwrite(&header.Height, 4, 1, fPointer_d);
  	fwrite(&header.Planes, 2, 1, fPointer_d);
  	fwrite(&header.BitPerPixel, 2, 1, fPointer_d);
  	fwrite(&header.Compression, 4, 1, fPointer_d);
  	fwrite(&header.ImageSize, 4, 1, fPointer_d);
  	fwrite(&header.XResolution, 4, 1, fPointer_d);
  	fwrite(&header.YResolution, 4, 1, fPointer_d);
  	fwrite(&header.Colors, 4, 1, fPointer_d);
  	fwrite(&header.ImportantColors, 4, 1, fPointer_d);
  	fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fPointer_d);
  	
  	
  	/* write RGB data */
	fwrite(img_d, 1, header.ImageSize *3, fPointer_d);
	fclose(fPointer_d);
	
	/* free meomry */
	free(palette);
	free(img_s);
	free(img_d);
	
	return 0;
}

int main(){
	unsigned char srcFileName[] = "lena.bmp";
	unsigned char desFileName[] = "processed_lena_rgb2gray.bmp";
	
	ImageProcessing(srcFileName, desFileName);
	printf(">> Finish.");
	return 0;
}



