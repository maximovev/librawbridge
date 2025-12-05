#include "pch.h"
#include "librawbridge.h"

#include "../libraw/libraw.h"

bool IsOpened=false;

RAWInfo raw_file_info;

LibRaw RawConverter;

int LibRAW_Result = 0;

int OpenRAWFile(char* filename)
{
	if(!IsOpened)
	{
		LibRAW_Result = RawConverter.open_file(filename);
		if (LibRAW_Result == LIBRAW_SUCCESS)
		{
			LibRAW_Result = RawConverter.unpack();
			if (LibRAW_Result == LIBRAW_SUCCESS)
			{
				IsOpened = true;
			}
		}
	}
	else
	{
		return LIBRAWBRIDGE_STATUS_FAIL;
	}

	return LIBRAWBRIDGE_STATUS_OK;
}

int GetRAWWidth()
{
	return 0;
}
int GetRAWHeight()
{
	return 0;
}

unsigned short GetPixelValue(int x, int y)
{
	return 0;
}
char GetPixelColor(int x, int y)
{
	return 0;
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