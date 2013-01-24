// case_report.h ��������������н���ĺ���
// wanghui 2007-8-13

#ifndef __CASE_REPORT_H__
#define __CASE_REPORT_H__
namespace case_report
{
	/*
	����������������ļ���λ�ڰ���.exeͬ·���£������ǣ�"����.exe.csv"
	*/
	// pcszModuleName == NULL, ���ݵ�ǰModule��ȡ����
	// pcszModuleName != NULL, ����ָ��Module��ȡ����
	const char* GetReportFileA(const char* pcszModuleName = NULL);

	/*
	ÿ������.exe��ʼִ��ʱ���͵���Clear��������ļ�
	*/
	// pcszModuleName == NULL, ���ݵ�ǰModule��������ļ�
	// pcszModuleName != NULL, ����ָ��Module��������ļ�
	void ClearA(const char* pcszModuleName = NULL);
	
	/*
	ÿִ���갸���е�һ��case���͵���һ��Report
	pcszDateTime �������ں�ʱ��
	pcszOwnner ����������
	pcszExe ����.exe������
	pcszCase �����е�case����
	pcszStat ��case�Ƿ�ͨ�� (passed, failed)
	*/
	// pcszModuleName == NULL, ���ݵ�ǰModule����һ����¼
	// pcszModuleName != NULL, ����ָ��Module����һ����¼
	void ReportA(const char* pcszDateTime, const char* pcszOwnner, const char* pcszExe, const char* pcszCase, const char* pcszStat, const char* pcszModuleName = NULL);

	// ����¼�����ָ���ļ�
	void ReportToFileA(const char* pcszFileName, const char* pcszDateTime, const char* pcszOwnner, const char* pcszExe, const char* pcszCase, const char* pcszStat);

}

#endif // __CASE_REPORT_H__