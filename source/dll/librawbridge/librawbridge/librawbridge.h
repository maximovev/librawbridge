#pragma once

#ifndef __librawbridge__
#define __librawbridge__

#ifndef __DLL
	#define __DLL extern "C" __declspec(dllexport)
#else
	#error Please redefine __DLL
#endif

typedef struct
{
	int ISO;
}ImageInfo;

typedef struct
{
	bool IsOpened;
	int Raw_Height;
	int Raw_Width;
	int Image_Height;
	int Image_Width;
	ImageInfo RAWImageInfo;
} RAWInfo;

enum
{
	LIBRAWBRIDGE_STATUS_OK=0,
	LIBRAWBRIDGE_STATUS_FAIL=-1
} LIBRAWBRIDGE_OPERATION_STATUS;

enum
{
	LIBRAWBRIDGE_PIXEL_COLOR_R = 0,
	LIBRAWBRIDGE_PIXEL_COLOR_G = 1,
	LIBRAWBRIDGE_PIXEL_COLOR_B = 2,
	LIBRAWBRIDGE_PIXEL_COLOR_G1 = 3,
	LIBRAWBRIDGE_PIXEL_COLOR_G2 = 4
};

__DLL int				OpenRAWFile(unsigned char filename);

__DLL int				GetRAWWidth();
__DLL int				GetRAWHeight();
__DLL unsigned short	GetPixelValue(int x, int y);
__DLL char				GetPixelColor(int x, int y);

__DLL int				CloseRAWFile();


#endif