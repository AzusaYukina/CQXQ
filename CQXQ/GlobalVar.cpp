#include "GlobalVar.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <string>
#include <map>
#include <atomic>
#include "ctpl_stl.h"
#include "GUI.h"

HMODULE hDllModule;

// ���в��
std::map<int, native_plugin> plugins;

// ���������в���¼�
std::map<int, std::vector<eventType>> plugins_events;

// ��һ�������ID
int nextPluginId = 1;

// XQ��Ŀ¼, ��β����б��
std::string rootPath;

// �����¼��Ƿ��Ѿ������ã�������QQ��½�ɹ��Ժ��ٵ��������¼�
bool EnabledEventCalled = false;

// �Ƿ���������Լ����¼�
bool RecvSelfEvent = false;

// �Ƿ�������
std::atomic<bool> running = false;

// α���߳�
ctpl::thread_pool fakeMainThread(1);

// API�����߳�
ctpl::thread_pool p(4);

std::atomic<long long> robotQQ;

unsigned char* AuthCode = nullptr;