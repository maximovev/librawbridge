#include "pch.h"
#include "librawbridge.h"

#include "../libraw/libraw.h"

bool IsOpened=false;

RAWInfo raw_file_info;

LibRaw RawConverter;

int LibRAW_Result = 0;

int OpenRAWFile(char* filename)
{
	int status=status=LIBRAWBRIDGE_STATUS_FAIL;
	if(!IsOpened)
	{
		LibRAW_Result = RawConverter.open_file(filename);
		if (LibRAW_Result == LIBRAW_SUCCESS)
		{
			LibRAW_Result = RawConverter.unpack();
			if (LibRAW_Result == LIBRAW_SUCCESS)
			{
				IsOpened = true;
				status=LIBRAWBRIDGE_STATUS_OK;
			}
		}
	}
	return status;
}

unsigned short GetRAWWidth()
{
	unsigned short result = 0;
	if (IsOpened)
	{
		result=RawConverter.imgdata.sizes.raw_width;
	}
	return result;
}

unsigned short  GetRAWHeight()
{
	unsigned short result = 0;
	if (IsOpened)
	{
		result = RawConverter.imgdata.sizes.raw_height;
	}
	return result;
}

unsigned short GetPixelValue(int x, int y)
{
	unsigned short result = 0;

	unsigned short height = GetRAWHeight();
	unsigned short width = GetRAWWidth();

	if (IsOpened)
	{
		if (x < width)
		{
			if(y < height)
			{
				result = RawConverter.imgdata.rawdata.raw_image[x + y * width];
			}
		}
	}

	return result;
}
char GetPixelColor(int x, int y)
{
	unsigned short result = 0;

	unsigned short height = GetRAWHeight();
	unsigned short width = GetRAWWidth();

	if (IsOpened)
	{
		if (x < width)
		{
			if (y < height)
			{
				result = RawConverter.imgdata.rawdata.[x + y * width];
			}
		}
	}

	return result;
}
int	CloseRAWFile()
{
	if (IsOpened)
	{
		RawConverter.recycle();
		IsOpened = false;
	}
	return 0;
}