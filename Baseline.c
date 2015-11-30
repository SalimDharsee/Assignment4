#include <stdio.h>
#include <stdlib.h>


struct wavfile
{
	char	chunkID[4];
	int 	chunkSize;
	char 	format[4];
	char 	subChunkID[4];
	int 	subChunkSize;
	short int 	audioFormat;
	short int 	num_channels;
	int 	sampleRate;
	int 	byteRate;
	short int 	blockAllign;
	short int 	bitsPSample;
	char 	subChunkID2[4];
	int 	subChunkSize2;
};

struct IRfile
{
	char	chunkID[4];
	int 	chunkSize;
	char 	format[4];
	char 	subChunkID[4];
	int 	subChunkSize;
	short int 	audioFormat;
	short int 	num_channels;
	int 	sampleRate;
	int 	byteRate;
	short int 	blockAllign;
	short int 	bitsPSample;
	char 	subChunkID2[4];
	int 	subChunkSize2;
};

int main(int argc, char *argv[]) {

	//printf("inputFile: %s\n", argv[1]);
	//printf("IRfile: %s\n",argv[2]);
	//printf("outputFile: %s\n", argv[3]);

	FILE	*fp;

	struct wavfile header;

	fp = fopen("CouperinBarricadesMysterieuses.wav", "rb");
	if (fp == NULL){
		printf("cant open file");
	} else {
		fread(&header,sizeof(header),1,fp);
		printf("%c\n",header.format[0]);

	}

	struct IRfile irHeader;
	fp = fopen("l960auto_park.wav", "rb");
	if (fp == NULL){
		printf("cant open file");
	} else {
		fread(&irHeader,sizeof(irHeader),1,fp);
		printf("%c\n",irHeader.format[0]);

	}
	 //Comment

	return argc;
}

void convovle(float x[], int N, float h[], int M, float y[], int P){

	int n, m;
	// clear output buffers
	for( n=0; n < P; n++){
		y[n] = 0;
	}

	// outer loop: process each input value x[n]

	for( n =0; n < N; n++){

		// inner loop process x[n] with each sample of h[n]
		for( m=0; m<M; m++){

			y[n+m] += x[n] * h[m];
		}
	}
}
