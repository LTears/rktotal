// case_report.inl ��������������н���ĺ���
// wanghui 2007-8-13
#include "case_report.h"
namespace case_report
{
	/*
	����������������ļ���λ�ڰ���.exeͬ·���£������ǣ�"����.exe.csv"
	*/
	const char* GetReportFileA(const char* pcszModuleName)
	{
		static char szModuleFileName[MAX_PATH] = {0};
		if (0 == szModuleFileName[0])
		{
			if (NULL == pcszModuleName || 0 == pcszModuleName[0])
			{
				::GetModuleFileName(NULL, szModuleFileName, MAX_PATH);
			}
			else
			{
				strcpy(szModuleFileName, pcszModuleName);
			}
			strcat(szModuleFileName, ".caserpt.csv");
		}
		return szModuleFileName;
	}

	/*
	ÿ������.exe��ʼִ��ʱ���͵���Clear��������ļ�
	*/
	void ClearA(const char* pcszModuleName)
	{
		remove(GetReportFileA(pcszModuleName));
	}
	/*
	ÿִ���갸���е�һ��case���͵���һ��Report
	pcszDateTime �������ں�ʱ��
	pcszOwnner ����������
	pcszExe ����.exe������
	pcszCase �����е�case����
	pcszStat ��case�Ƿ�ͨ�� (passed, failed)
	*/
	void ReportA(const char* pcszDateTime, const char* pcszOwnner, const char* pcszExe, const char* pcszCase, const char* pcszStat, const char* pcszModuleName)
	{
		ReportToFileA(GetReportFileA(pcszModuleName), pcszDateTime, pcszOwnner, pcszExe, pcszCase, pcszStat);
	}

	void ReportToFileA(const char* pcszFileName, const char* pcszDateTime, const char* pcszOwnner, const char* pcszExe, const char* pcszCase, const char* pcszStat)
	{
		std::ofstream ofs;
		ofs.open(pcszFileName, std::ios::out | std::ios::app);
		if (ofs.good())
		{
			ofs.seekp(0, std::ios::end);
			if (0 == ofs.tellp())
				ofs << "DateTime,Ownner,Exe,Case,Stat\n";

			ofs << pcszDateTime << ',' << pcszOwnner << ',' << pcszExe << ',' << pcszCase << ',' << pcszStat;
			ofs << '\n';
		}
	}
}
