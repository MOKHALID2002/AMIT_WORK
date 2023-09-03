#ifndef headers_h_
#define headers_h_

typedef unsigned int uint8;

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8,uint8,uint8*,uint8*);
void SDB_DeleteEntry(uint8);
void SDB_ReadEntry(uint8);
void SDB_GetIdList(uint8*,uint8*);
bool SDB_IsIdExist(uint8);

#endif

