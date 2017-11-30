#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int getFileList(const char * path, pStringArr pathList) {
	struct _finddata_t data;
	char path_local[1024] = { 0 };

	char * path_tmp = (char *)malloc(sizeof(char)* (strlen(path) + 4));
	strcpy(path_tmp, path);
	strcat(path_tmp, "*.*");

	long hnd = _findfirst(path_tmp, &data);
	int  nRet;
	if (hnd < 0) {
		_findclose(hnd);
		return hnd;
	}else {
		nRet =  1;
	}
	
	while (nRet >= 0)
	{
		memset(path_local,0,1024);
		strcpy(path_local, path);
		strcat(path_local, data.name);
	
		if (data.attrib != _A_SUBDIR) {
			addOne(pathList, path_local);
		}else if( strcmp(data.name,".")!=0 && strcmp(data.name, "..")!=0 ) {
			strcat(path_local, symbol);
			getFileList(path_local, pathList);
		}
		// 如果是目录
			
		nRet = _findnext(hnd, &data);
	}
	_findclose(hnd);     // 关闭当前句柄+		data	{attrib=16 time_create=1487761830 time_access=1507476766 ...}	_finddata64i32_t

	return 0;
}

int findSubStr(pStringArr pathList, pStringArr findList, const char * subStr) {

	for (int x = 0; x < pathList->length; x++) {

		FILE* f = fopen(pathList->pHead[x].pStr, "r");

		fseek(f, 0, SEEK_END);

		size_t size = ftell(f);

		fseek(f, 0, 0);

		char* text = (char*)calloc(size + 1, 1);

		fread(text, 1, size, f);

		fclose(f);
		text[size] = 0;
		char *pos = strstr(text, subStr);

		if (pos) {
			free(text);
			addOne(findList, pathList->pHead[x].pStr);
		}
	}
}

