#include "functions.h"
#include "StringUtil.h"

void main()
{
	pStringArr pathList = createStrArr();
	pStringArr findList = createStrArr();


	getFileList("C:\\Users\\82529\\Desktop\\C find\\dataset\\dataset\\", pathList);


	findSubStr(pathList, findList, "vulnerability");
	
	

	sortStr(findList,1);

	for (int x = 0; x < findList->length; x++) {
		printf("%s\n", findList->pHead[x].pStr);
	}

	destroyStrArr(pathList);
	destroyStrArr(findList);
	getchar();
	
}