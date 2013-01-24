/* -------------------------------------------------------------------------
//	�ļ���		��	xmlcfg/expansile_string.h
//	������		��	Jiang Wangsheng
//	����ʱ��	��	2008-10-29 ���� 11:17:10
//	��������	��	���ַ�����ʼ�����ض����ַ���������չ����expat_reader
					��xml������ֵ�Ľ������õ�����һ������
					����������$(home)-->c:\app��ExpansileString
					�����$(home)\jiang ��չΪ c:\app\jiang					
//					
//					
//
//	$Id: $
// -----------------------------------------------------------------------*/
#ifndef __XMLCFG_EXPANSILE_STRING_H__
#define __XMLCFG_EXPANSILE_STRING_H__

#ifdef _USER_MODE_
# include <string>
#else
# include "kernel_stl/string.hpp"
#endif


// -------------------------------------------------------------------------
namespace xmlcfg {
// -------------------------------------------------------------------------


struct ExpansileString 
{
	WCHAR* unexpanded;		// δ��չ���ַ���
	size_t cchUnexpanded;	 
	WCHAR* expanded;	// ��չ����ַ�����NULL��ʾ��Ч����""��Ч
	size_t cchExpanded;
};

inline
void getExpandedString( LPCWSTR szInput, std::wstring &strOutput,
					    ExpansileString* pEStrs, ULONG nEStrs )
{
	size_t cchInput = wcslen( szInput );
	strOutput.assign( szInput, cchInput );

	for ( ULONG l = 0; l < nEStrs; ++l )
	{
		if ( pEStrs[l].expanded == NULL )
			continue;
		if ( cchInput < pEStrs[l].cchUnexpanded )
			continue;
#ifdef _USER_MODE_
		if ( memcmp( pEStrs[l].unexpanded, szInput, pEStrs[l].cchUnexpanded * sizeof(WCHAR) ) == 0 )
#else
		if ( RtlCompareMemory( pEStrs[l].unexpanded, szInput, pEStrs[l].cchUnexpanded * sizeof(WCHAR) ) == 
				pEStrs[l].cchUnexpanded * sizeof(WCHAR) )
#endif				
		{
			strOutput.assign( pEStrs[l].expanded, pEStrs[l].cchExpanded );
			if ( cchInput > pEStrs[l].cchUnexpanded )
				strOutput.append( szInput + pEStrs[l].cchUnexpanded, cchInput - pEStrs[l].cchUnexpanded );
			break;
		}							
	}
}

// -------------------------------------------------------------------------
}
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
//	$Log: $

#endif /* __XMLCFG_EXPANSILE_STRING_H__ */
