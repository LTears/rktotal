#pragma once

const unsigned char GIV[]={0x12,0x34,0x56,0x78,0x90,0xAB,0xCD,0xEF};
class CDes
{
public:
	CDes();
	~CDes();
public :
	enum PADDING_MODE		//���ģʽö��
	{
		PKCS5=0				
	};
	enum CIPHER_MODE		//��������ģʽ
	{
		ECB=0,
		CBC=1
	};
	//���ܽӿں���
	char* Encrypt ( const char key[8], char* data, int& dataLen, PADDING_MODE pad, CIPHER_MODE cip, const unsigned char IV[8]=GIV);
	//���ܽӿں�
	char* Decrypt ( const char key[8], char* data, int &resultLength, PADDING_MODE pad, CIPHER_MODE cip, const unsigned char IV[8]=GIV);
	char* Decrypt2 ( const char key[8], char* data, int nDataLen, int &resultLength, PADDING_MODE pad, CIPHER_MODE cip, const unsigned char IV[8]=GIV);
private:
	char* m_encryptBuf;
	char* m_decryptBuf;
	unsigned long m_eBufLen;
	unsigned long m_dBufLen; 

	int paddingWithPKCS5( char* pData, int dataLen);
	int unPaddingWithPKCS5( char* pData, int dataLen);
	unsigned long allocEncode(unsigned long newSize);
	unsigned long allocDecode(unsigned long newSize);
};
