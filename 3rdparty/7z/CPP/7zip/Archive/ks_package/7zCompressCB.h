#pragma once
//�ص�
#include "Common/MyCom.h"
#include "Common/ComTry.h"
#include "Common/MyString.h"
#include "../../Common/FileStreams.h"
#include "../IArchive.h"
//��Ҫѹ�����ļ��ṹ��
typedef class tagPackItem
{
public:    
    tagPackItem()
    {

    }
    //�Ƿ���Ŀ¼
    BOOL IsDir() const
    {
        if (ByFileInfo.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
        {
            return TRUE;
        }
        return FALSE;
    }
    UString m_strFilePath;
    BY_HANDLE_FILE_INFORMATION ByFileInfo;

}KSPackItem, *PKSPackItem;

//ѹ���ص���
class C7zCompressCallback : public IArchiveUpdateCallback2,
                      public CMyUnknownImp
{
public:
    C7zCompressCallback();
    ~C7zCompressCallback();

    MY_UNKNOWN_IMP1(
        IArchiveUpdateCallback2)

    INTERFACE_IArchiveUpdateCallback2(;)

public:
    BOOL SetCompressDir(LPCWSTR lpDir);
    int GetSize() const
    {
        return m_vecKSPackItem.Size();
    }

private:
    HRESULT PushSingleFileToVector(LPCWSTR lpFilePath);
    HRESULT PushAllFilesToVector(LPCWSTR lpFilePath);

    //��Ҫ������ļ�
    CRecordVector<KSPackItem*> m_vecKSPackItem;
    //ѹ��·����ƫ��
    int m_nPathOff;
    UString m_ustrDir;
  
};
