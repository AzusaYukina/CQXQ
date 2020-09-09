#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <string>
#include <atomic>
#include <map>
#include "ctpl_stl.h"

extern HMODULE hDllModule;

struct eventType
{
	int plugin_id = -1;
	int priority = 30000;
	FARPROC event = nullptr;
	bool operator<(const eventType& that) const
	{
		return this->priority < that.priority;
	}
	bool operator==(const eventType& that) const
	{
		return this->event == that.event;
	}
};

struct native_plugin
{
	int id = -1;
	std::string file;
	std::string newFile;
	std::string name;
	std::string version;
	int version_id = -1;
	std::string author;
	std::string description;
	std::map<int, eventType> events;
	std::vector<std::pair<std::string, FARPROC>> menus;
	HMODULE dll = nullptr;
	bool enabled = false;

	native_plugin(int i, const std::string& f, const std::string& nf)
	{
		id = i;
		file = f;
		newFile = nf;
		dll = nullptr;
		enabled = true;
	}

	native_plugin() = default;
	~native_plugin() = default;
};

// �洢���в��
extern std::map<int, native_plugin> plugins;

// �洢���������в���¼�
extern std::map<int, std::vector<eventType>> plugins_events;

// ��һ�������id
extern int nextPluginId;

// XQ��Ŀ¼, ��β����б��
extern std::string rootPath;

// �����¼��Ƿ��Ѿ������ã�������QQ��½�ɹ��Ժ��ٵ��������¼�
extern bool EnabledEventCalled;

// �Ƿ���������Լ����¼�
extern bool RecvSelfEvent;

// �Ƿ�������
extern std::atomic<bool> running;

// α���߳�
extern ctpl::thread_pool fakeMainThread;

// API�����߳�
extern ctpl::thread_pool p;

extern std::atomic<long long> robotQQ;

extern unsigned char* AuthCode;