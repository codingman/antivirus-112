/*!
 * (C) 2002 "Kaspersky Lab"
 *
 * \file PRTS/TasksStorage.h
 * \author ������ �������
 * \date 2002
 * \brief ��������� ��� ������ �� �������� �����, ��������������� � ���������� ���
 *        ����������� ���������.
 *
 */
/*KLCSAK_PUBLIC_HEADER*/

#ifndef KLPRTS_TASKSSTORAGE_H
#define KLPRTS_TASKSSTORAGE_H

/*KLCSAK_BEGIN_PRIVATE*/
#include <string>
/*KLCSAK_END_PRIVATE*/

#include <std/err/error.h>
#include <std/par/params.h>

/*KLCSAK_BEGIN_PRIVATE*/
#include <kca/prci/componentid.h>
/*KLCSAK_END_PRIVATE*/

#include <std/sch/task.h>

namespace KLPRTS
{
	/*!
		��� ���� ��� ������ Updater ��� __����__ ���������
	*/
	const wchar_t PRTS_PRODUCT_UPDATER_TASK_TYPE_NAME[] = L"KLUPD_TA_UPDATE_TASK";

	/*!
		������������������ ��������� ��� ����� � ���������� 'params' �������� ������
		��� ���������� ���������� ������
	*/
	const wchar_t c_szwTaskSystemFlag[]=L"klprts-TaskSystemFlag";	// BOOL_T Flag for system task

	const wchar_t c_szwTaskSystemEnableFlag[]=L"klprts-TaskEnableSystemFlag";	// BOOL_T ���� ������ ��������� �� ������ �������� ��������� ������ ������ �� ����������

	// ������ �������� ����������� � ��������� 'params' �������� ������ � TaskStorage.

	/*!
		���� ����������� � Params ����� ��� �� �������
	*/
	const wchar_t c_szwTaskScheduledFlag[]=L"klprts-TaskScheduledFlag";	// BOOL_T Flag for task run by scheduler

	/*!
		���� ����������� � Params ����� ��� �� �������
	*/
	const wchar_t c_szwTaskPreparativeStartFlag[]=L"klprts-TaskPreparativeStartFlag";	// BOOL_T Flag for preparative start of task
	
	/*!
		���� ����������� � Params ����� ��� �� �������
	*/
	const wchar_t c_szwTaskPreparativeTimeout[]=L"klprts-TaskPreparativeTimeout";	// INT_T Perparative task timeout. exists only if it's preparative start

	/*!
		���� ����������� � Params ����� ��� �� �������
		���� ������� ���� ��� � ���������� �������, �� ��� ������ ������ ������������ � ������ �� ������
		����� ��������� �������� LogonUser
	*/
	const wchar_t c_szwTaskLogonUserResult[]=L"klprts-TaskLogonUserResult";	// BOOL_T result of LogonUser

	/*!
		���� ��������� ��� �������� ������ � ��������, ��� ������ ������� ����������� ��� ������ �� ������ ���������
	*/
	const wchar_t c_szwTaskHasPredefinedTargetList[]=L"klprts-TaskHasPredefinedTargetList";	// BOOL_T

	/*!
		���� ����������� � Params ����� ��� �� �������
	*/
	const wchar_t c_szwTaskParamTaskInfo[]=L"klprts-TaskParamTaskInfo";	// PARAMS_T TaskInfo ���������� ������

	/*!
		������������� ������ � TaskStorage.
	*/
	const wchar_t	c_szwTaskStorageId[]=L"klprts-TaskStorageId";// STRING_T

    /*!
    * \brief INT_T - �������� ������ ������ (� �������) � ����������� KLPRTS_TSKSCHTYPE_STARTUP_EX
					 ����� ������ ����������
    */
	const wchar_t c_szwDelayOnAppTaskStart[] = L"klprts-DelayOnAppTaskStart";

    /*!
    * \brief PARAMS_T - ��������� ������� ������ �� ������
			KLPRTS_START_CONDITION
				KLPRTS_START_CONDITION_TYPE
				KLPRTS_START_CONDITION_VALUE
    */
	enum ETskStartCondition{
		TSC_NONE,
		TSC_AV_DB_UPDATED,
		TSC_VIRUS_ATTACK,
		TSC_TASK_COMPLETED
	};
	const wchar_t KLPRTS_START_CONDITION[] = L"KLPRTS_START_CONDITION";				// PARAMS_T
	const wchar_t KLPRTS_START_CONDITION_TYPE[] = L"KLPRTS_START_CONDITION_TYPE";	// INT_T (��. ETskStartCondition)
	/*!
    * \brief  ������� �� ���� �������
		TSC_AV_DB_UPDATED : �����������
		TSC_VIRUS_ATTACK : INT_T (��. KLEVP::EVirusOutbreakType)
		TSC_TASK_COMPLETED : STRING_T (task_id ���������/���������� ������, �� ���������� ������� ������� ��������� ������)
	*/
	const wchar_t KLPRTS_START_CONDITION_VALUE[] = L"KLPRTS_START_CONDITION_VALUE";

	/*!
    * \brief  ������� �� ���� �������
		TSC_AV_DB_UPDATED : �����������
		TSC_VIRUS_ATTACK : �����������
		TSC_TASK_COMPLETED : INT_T (KLPRTS::TaskState - TASK_COMPLETED ��� TASK_FAILURE)
	*/
	const wchar_t KLPRTS_START_CONDITION_VALUE_EX[] = L"KLPRTS_START_CONDITION_VALUE_EX";

	/*!
		������� ������ ��� ������� ������.
	*/
	const wchar_t c_szwTaskAccounts[]=L"klprts-TaskAccounts";				// ARRAY_T Account: ������ ������� ������� ��� ������ (���� �������������� �������)
	const wchar_t c_szwTaskAccountUser[]=L"klprts-TaskAccountUser";			// STRING_T Account: user name
	const wchar_t c_szwTaskAccountPassword[]=L"klprts-TaskAccountPassword";	// BYNARY_T Account: encrypted password

	// ������ �������� ����������� � ��������� 'paramsTaskInfo' �������� ������ � TaskStorage.

	const wchar_t c_szwWakeOnLAN[]=L"klprts-WakeOnLAN";	// INT_T ����� ���������� ����� �������� ������ ��� ����������� ���������� �� ����

	const wchar_t c_szwTaskNotificationOverall[]=L"klprts-TaskNotificationOverall";	// BOOL_T Notification Overall
	const wchar_t c_szwTaskNotificationFailure[]=L"klprts-TaskNotificationFailure";	// BOOL_T Notification failure
	const wchar_t c_szwTaskNotificationAllResults[]=L"klprts-TaskNotificationAllResults";	// BOOL_T Notification All Results

//	const wchar_t c_szwTaskSaveResults[]=L"klprts-TaskSaveResults";// BOOL_T Save task results
	const wchar_t c_szwTaskSaveResultsLifespan[]=L"klprts-TaskSaveResultsLifespan";	// INT_T(days) Save Results Lifespan
	const wchar_t c_szwTaskSaveResultsOnClient[]=L"klprts-TaskSaveResultsOnClient";	// BOOL_T(days) Save Results on client
	const wchar_t c_szwTaskSaveResultsOnClientEventLog[]=L"klprts-TaskSaveResultsOnClientEventLog";	// BOOL_T(days) Save Results on client EventLog
	const wchar_t c_szwTaskSaveResultsOnServerEventLog[]=L"klprts-TaskSaveResultsOnServerEventLog";	// BOOL_T(days) Save Results on server EventLog

	const wchar_t c_szwTaskMaxRuningTime[]=L"klprts-TaskMaxRunningTime";	// INT_T (secs)
	const wchar_t c_szwScheduleSubtype[] = L"klprts-TaskScheduleSubtype";	// INT_T ��� ���������� ���������� ��� ������ (��. KLPRTS_TSKSCHTYPE_XXXX)

	/*!
    * \brief  c_szwScheduleSubtypeEx - INT_T ����������� ��� ���������� ���������� ��� ������
	*	����� ���������:
	*	KLPRTS_TSKSCHTYPE_START_AFTER_SERVER_UPDATE
	*	KLPRTS_TSKSCHTYPE_ON_VIRUS_OUTBREAK
	*	KLPRTS_TSKSCHTYPE_ON_OTHER_TASK_END
	* !! ��� ���� � c_szwScheduleSubtype ��� ������������� ������������� ��� KLPRTS_TSKSCHTYPE_MANUALLY !!
	*/
	const wchar_t c_szwScheduleSubtypeEx[] = L"klprts-TaskScheduleSubtypeEx";	

	const wchar_t c_szwShutdownSystemAfterRun[]=L"klprts-ShutdownSystemAfterRun";	// BOOL_T ������� ������������� ���������� ���������� ����� ����� ���������� ������

	typedef enum _tagKLPRTS_TSKSCHTYPE{
		KLPRTS_TSKSCHTYPE_NHOURS = 0x01,		// ������ N - �����, ������� � (����)
		KLPRTS_TSKSCHTYPE_NDAYS = 0x02,			// ������ N - ����, ������� � (����)
		KLPRTS_TSKSCHTYPE_NWEEKS = 0x04,		// ������ N - ������, ������� � (����)
		KLPRTS_TSKSCHTYPE_DAYLY = 0x08,
		KLPRTS_TSKSCHTYPE_WEEKLY = 0x10,
		KLPRTS_TSKSCHTYPE_MONTHLY = 0x20,
		KLPRTS_TSKSCHTYPE_ONCE = 0x40,
		KLPRTS_TSKSCHTYPE_STARTUP = 0x80,
		KLPRTS_TSKSCHTYPE_MANUALLY = 0x100,
		KLPRTS_TSKSCHTYPE_IMMEDIATELY = 0x200,
		KLPRTS_TSKSCHTYPE_EVERY_N_MINUTES = 0x400,
		KLPRTS_TSKSCHTYPE_START_AFTER_UPDATE = 0x800,
		KLPRTS_TSKSCHTYPE_STARTUP_EX = 0x1000,
		KLPRTS_TSKSCHTYPE_AUTOMATIC = 0x2000,
		KLPRTS_TSKSCHTYPE_START_AFTER_SERVER_UPDATE = 0x4000,	// see KLTSK::ETskStartCondition
		KLPRTS_TSKSCHTYPE_ON_VIRUS_OUTBREAK = 0x8000,			// see KLTSK::ETskStartCondition
		KLPRTS_TSKSCHTYPE_ON_OTHER_TASK_END = 0x10000,
		KLPRTS_TSKSCHTYPE_WEEKLY_EX = 0x20000
	} KLPRTS_TSKSCHTYPE;

	const long KLPRTS_TSKSCHTYPE_DEFAULT =	KLPRTS_TSKSCHTYPE_NHOURS |
											KLPRTS_TSKSCHTYPE_DAYLY | 
											KLPRTS_TSKSCHTYPE_WEEKLY | 
											KLPRTS_TSKSCHTYPE_MONTHLY | 
											KLPRTS_TSKSCHTYPE_ONCE | 
//											KLPRTS_TSKSCHTYPE_STARTUP | 
											KLPRTS_TSKSCHTYPE_MANUALLY |
											KLPRTS_TSKSCHTYPE_IMMEDIATELY |
											KLPRTS_TSKSCHTYPE_START_AFTER_SERVER_UPDATE |
											KLPRTS_TSKSCHTYPE_ON_VIRUS_OUTBREAK |
											KLPRTS_TSKSCHTYPE_ON_OTHER_TASK_END;

    /*!
    * \brief BOOL_T - ������ ������ �� ����� ���� ������� ���������� ������� Admin Kit
    */
	const wchar_t c_szwTaskCannotBeDeleted[] = L"klprts-TaskCannotBeDeleted";

    /*!
    * \brief BOOL_T - ������ ������ �� ������ ���������������� �� ����������� �������
    */
	const wchar_t c_szwDontApplyToSlaveServers[] = L"klprts-DontApplyToSlaveServers";

    /*!
    * \brief ������������� ������ �� �����
    */
	const wchar_t KLPRTS_TASK_INVALID_ID[] = L"";
	const wchar_t KLPRTS_LOCAL_TASK_ATTRIBUTE[] = L"_LOCAL_";

    /*!
    * \brief ����� �������� �����
    *
    */
	const wchar_t TASK_STORAGE_NAME_LOCAL[] = L"PRTS_TASK_STORAGE_LOCAL";	// ��������� ���������

    /*!
    * \brief ��� ���������, ����������� display name ��� task'a �
            ���������� Params* paramsTaskInfo (��. ����� AddTask)
    *
    */
    const wchar_t TASK_DISPLAY_NAME[] = L"DisplayName";			// STRING_T

    /*!
    * \brief ��� ���������, ����������� ���� Enabled ��� ������ �
            ���������� Params* parTaskInfo
    *
    */
    const wchar_t TASK_ENABLED_FLAG[] = L"PRTS_TASK_ENABLED";	// BOOL_T

    /*!
    * \brief ��� ���������, ����������� ��� ������ ������� ����������� ��� ������ �
            ���������� Params* parTaskInfo (��. TCT_XXXX)
    *
    */
    const wchar_t TASK_TARGET_COMPUTERS_TYPE[] = L"PRTS_TASK_TARGET_COMPUTERS_TYPE";	// INT_T
	typedef enum _tagTCT{
		TCT_WINDOWS_NETWORKING,
		TCT_IP_NETWORKING
	} TCT;

    /*!
    * \brief ��� ���������, ����������� ID ������ � ������� ������ ���������� �
            ���������� Params* parTaskInfo(������ ��� ��������� �����)
    *
    */
    const wchar_t TASK_GROUPID_FOR_GROUP_TASKS[] = L"PRTS_TASK_GROUPID";	// INT_T

    /*!
    * \brief ��� ���������, ����������� ����� �������� ������ �
            ���������� Params* parTaskInfo
    *
    */
    const wchar_t TASK_CREATION_DATE[] = L"PRTS_TASK_CREATION_DATE";	// DATETIME_T

    /*!
    * \brief ����� ���������� � EventBody
    *
    */

	const wchar_t EVENT_BODY_PARAM_NAME_TASKID[] = L"PRTS_TaskID";		// [int] ID ������, ��������� ��������� �������

    /*!
    * \brief ������������ �������
    */

	const wchar_t EVENT_TYPE_NEW_TASK[] = L"PRTS_NewTask";				// ������� ����� ������
	const wchar_t EVENT_TYPE_TASK_DELETED[] = L"PRTS_TaskDeleted";		// ������ �������
	const wchar_t EVENT_TYPE_TASK_UPDATED[] = L"PRTS_TaskUpdated";		// �������� ��������� ������

    /*!
    * \brief ���� Event�� ������� ������
    */

	const wchar_t PRTS_TASK_START_EVENT_NONE[] = L"PRTS_EVENT_NONE";	// �� ����� Event ������� ������

/*KLCSAK_BEGIN_PRIVATE*/

    /*!
    * \brief ��������� ��� ������ � ��������������� � ���������� ������� �����
    *        ����������� ���������.
    *
    */

    class TasksStorage : public KLSTD::KLBase {
    public:

    /*!
      \brief ������������� �� ������ �������� ��� ��������� ������ ���������������
             � ���������� ������������ ��������� �����.  ���� ���� �� ��������� �� �����,
             ���������� ����� �� �������� ����� ��������� �� ������������.

        \param filter      [in]  ������ �� �������������� ����������� ��� ���������.
        \param taskName    [in]  ��� ������, ��������������� ��� ����������.

    */
        virtual void ResetTasksIterator (
                        const KLPRCI::ComponentId & filter,
                        const std::wstring & taskName ) = 0;


    /*!
      \brief ���������� �������� ��������� ������ �� ������ ���������������
             � ���������� ������������ ��������� �����.

		\param taskId			[out]  ������������� ������ � Task Storage.
        \param componentId      [out]  ������������� ����������.
        \param taskName         [out]  ��� ������, ��������������� ��� ����������.
        \param task             [out]  �������� ��������������� � ���������� ������.
		\param params			[out]  ��������� ������
		\param paramsTaskInfo	[out]  �������������� ��������� ������
		\param startOnEvent     [out]  ����������� �� ������ ��� ������������� � ������� ������������� �������.

        \return ������� �� ��� ������ � ������.
    */
        virtual bool GetNextTask (
						std::wstring &taskId,
                        KLPRCI::ComponentId & id,
                        std::wstring & taskName,
						bool& bStartOnEvent,
                        KLSCH::Task ** task,
						KLPAR::Params** params,
						KLPAR::Params** paramsTaskInfo = NULL) = 0;

    /*!
      \brief ���������� �������� ������ � �������� ID �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId			[in]  ������������� ������ � Task Storage.
        \param componentId      [out]  ������������� ����������.
        \param taskName         [out]  ��� ������, ��������������� ��� ����������.
        \param task             [out]  �������� ��������������� � ���������� ������.
		\param params			[out]  ��������� ������
		\param paramsTaskInfo	[out]  �������������� ��������� ������
		\param startOnEvent     [out]  ����������� �� ������ ��� ������������� � ������� ������������� �������.

		���� ������ � ��������� ID �� ������� �� ����� ��������� ���������� STDE_NOTFOUND
    */
        virtual void GetTaskByID (
						const std::wstring &taskId,
                        KLPRCI::ComponentId & id,
                        std::wstring & taskName,
						bool& bStartOnEvent,
                        KLSCH::Task ** task,
						KLPAR::Params** params,
						KLPAR::Params** paramsTaskInfo = NULL) = 0;

    /*!
      \brief ��������� ����� ������ � ������ ��������������� � ���������� �����.

        \param componentId      [in]  ������������� ���������� ��� ���������� ������.
        \param taskName         [in]  ��� ������, ��������������� ��� ����������.
        \param task             [in]  �������� ��������������� � ���������� ������.
		\param params			[in]  ��������� ������
		\param paramsTaskInfo	[in]  �������������� ��������� ������

        \return ������������� ������ � ������ ��������������� � ���������� �����.
                �������� ������ Task Storage � ������������ ������� GetTaskId �
                �������� ������ (task->GetTaskId()).

    */
        virtual std::wstring AddTask (
                        const KLPRCI::ComponentId & id,
                        const std::wstring & taskName,
                        const KLSCH::Task * task,
						const KLPAR::Params* params,
						const KLPAR::Params* paramsTaskInfo = NULL) = 0;


    /*!
      \brief ��������� �������� ������ � ������ ���������������
             � ���������� ������������ ��������� �����.

		\param taskId			[in]  ������������� ������ � Task Storage.
        \param componentId      [in]  ������������� ���������� ��� ���������� ������.
        \param taskName         [in]  ��� ������, ��������������� ��� ����������.
        \param task				[in]  ����� �������� ��������������� � ���������� ������.
                                    ������������� ������ ��� ���������� ������������
                                    ����� ������ ������ GetTaskId � �������� ������
                                    (task->GetTaskId()).
		\param params			[in]  ��������� ������
		\param paramsTaskInfo	[in]  �������������� ��������� ������

    */
        virtual void UpdateTask (
						const std::wstring &taskId,
                        const KLPRCI::ComponentId & id,
                        const std::wstring & taskName,
                        const KLSCH::Task * task,
						const KLPAR::Params* params,
						const KLPAR::Params* paramsTaskInfo = NULL) = 0;



   /*!
      \brief ������� �������� ������ �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId      [in]  ������������� ������ � Task Storage ��� ��������.

    */
        virtual void DeleteTask ( const std::wstring &taskId ) = 0;

     /*!
      \brief �������������, �� ������ ������� ������ ����������� ������.

	������ ������ ���������� ������ �� �������, �� ������� ������ ����������� ������.
	���� ��� ������� ��� �������� ����� 'EventNone', �� ������ ������ �� �������� ������������.
	���� � ������ ��������� ���� 'RunMissed', �� ������ ����� ��������, ���� ���� �������
	��������� � �� �����, ����� ����� ����������������� �� ��� �������. � ������, �������
	����������� ������ �� ��������, ������ ���� ��� ���������� ScheduleNone.

		\param taskId       [in]  ������������� ������ ��� ��������� ����������.
		\param filter       [in]  ������ �� �������������� ����������� ��� ����������� �������.
		\param eventType    [in]  ��� ������� ��� �����������.
		\param bodyFilter   [in]  ������ �� ���� ������� ��� �����������.
    */
        virtual void SetTaskStartEvent (
			const std::wstring &taskId,
			const KLPRCI::ComponentId & filter,
			const std::wstring & eventType,
			const KLPAR::Params * bodyFilter) = 0;

     /*!
		\brief ���������� ���������� � �������, �� �������� ������ ����������� ������.

	���� ��� ������� ��� �������� ����� 'EventNone', �� ������ ������ �� �������� �� ������������.

		\param taskId       [in]  ������������� ������ ��� ��������� ����������.
		\param filter       [out]  ������ �� �������������� ����������� ��� ����������� �������.
		\param eventType    [out]  ��� ������� ��� �����������.
		\param bodyFilter   [out]  ������ �� ���� ������� ��� �����������.
    */
        virtual void GetTaskStartEvent (
			const std::wstring &taskId,
			KLPRCI::ComponentId & filter,
			std::wstring & eventType,
			KLPAR::Params ** bodyFilter) = 0;

     /*!
		\brief ���������� ��� ����� - ��������� ������

		\param taskId       [in]  ������������� ������ ��� ��������� ����������.
    */
		virtual std::wstring GetTaskFileName(const std::wstring &taskId) = 0;

    /*!
      \brief ���������� �������� ������ � �������� ID �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId			[in]  ������������� ������ � Task Storage.
        \param componentId      [out]  ������������� ����������.
        \param taskName         [out]  ��� ������, ��������������� ��� ����������.
        \param task             [out]  �������� ��������������� � ���������� ������.
		\param params			[out]  ��������� ������ (� ����������� ��������� !!!)
		\param paramsTaskInfo	[out]  �������������� ��������� ������
		\param startOnEvent     [out]  ����������� �� ������ ��� ������������� � ������� ������������� �������.

		���� ������ � ��������� ID �� ������� �� ����� ��������� ���������� STDE_NOTFOUND
    */
        virtual void GetTaskByIDWithPolicyApplied (
						const std::wstring &taskId,
                        KLPRCI::ComponentId & id,
                        std::wstring & taskName,
						bool& bStartOnEvent,
                        KLSCH::Task ** task,
						KLPAR::Params** params,
						KLPAR::Params** paramsTaskInfo = NULL) = 0;

		/*!
		  \brief ��������� ����� ������ � ������ ��������������� � ���������� �����.

			\param taskId			[in]  ���������������� ������������� ������.
			\param componentId      [in]  ������������� ���������� ��� ���������� ������.
			\param taskName         [in]  ��� ������, ��������������� ��� ����������.
			\param task             [in]  �������� ��������������� � ���������� ������.
			\param params			[in]  ��������� ������
			\param paramsTaskInfo	[in]  �������������� ��������� ������
		*/
		virtual void AddTaskWithID(const std::wstring &taskId,
								   const KLPRCI::ComponentId &id,
								   const std::wstring &taskName,
								   const KLSCH::Task *task,
								   const KLPAR::Params* params,
								   const KLPAR::Params* paramsTaskInfo) = 0;
    };

	//////////////////////////////////////////////////////////////////////////
	// TasksStorage2
	//////////////////////////////////////////////////////////////////////////

	/*!
    * \brief ��������� � ����������� � ������
    */
	struct TaskInfo {
		std::wstring wstrTaskId;
        KLPRCI::ComponentId cidComponentId;
        std::wstring wstrTaskName;
        KLSCH::Task* pTask;			// �� �������� ����� ������� �������� ������������
		KLSTD::CAutoPtr<KLPAR::Params> parTaskParams;
		KLSTD::CAutoPtr<KLPAR::Params> parTaskInfo;

	// ������ �� �������
		KLPRCI::ComponentId cidPublisher;
		std::wstring  wstrEventType;
		KLSTD::CAutoPtr<KLPAR::Params> parEventBodyFilter;

		TaskInfo() :
			pTask(NULL),
			wstrEventType(PRTS_TASK_START_EVENT_NONE)
		{
		}

		bool IsStartOnEvent() {
			return (wstrEventType != PRTS_TASK_START_EVENT_NONE);
		}
	};

    /*!
    * \brief ��������� ��� ������ � ��������������� � ���������� ������� �����
    *        ����������� ���������.
    *
    */

    class TasksStorage2 : public TasksStorage {
    public:

    /*!
      \brief ������������� �� ������ �������� ��� ��������� ������ ���������������
             � ���������� ������������ ��������� �����.  ���� ���� �� ��������� �� �����,
             ���������� ����� �� �������� ����� ��������� �� ������������.

        \param filter      [in]  ������ �� �������������� ����������� ��� ���������.
        \param taskName    [in]  ��� ������, ��������������� ��� ����������.

    */
        virtual void ResetTasksIterator (
                        const KLPRCI::ComponentId & filter,
                        const std::wstring & taskName ) = 0;

    /*!
      \brief ���������� �������� ��������� ������ �� ������ ���������������
             � ���������� ������������ ��������� �����.

		\param  TaskInfo&  	[out] ���������� � ������.

        \return ������� �� ��� ������ � ������.
    */
        virtual bool GetNextTask2 ( TaskInfo& ti ) = 0;

    /*!
      \brief ���������� �������� ������ � �������� ID �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId			[in]  ������������� ������ � Task Storage.
		\param  TaskInfo&  		[out] ���������� � ������.

		���� ������ � ��������� ID �� ������� �� ����� ��������� ���������� STDE_NOTFOUND
    */
        virtual void GetTaskByID2 (
						const std::wstring &taskId,
						TaskInfo& ti ) = 0;

    /*!
      \brief ���������� �������� ������ � �������� ID �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId			[in] ������������� ������ � Task Storage.
		\param  TaskInfo&  		[in] ���������� � ������.

		���� ������ � ��������� ID �� ������� �� ����� ��������� ���������� STDE_NOTFOUND
    */
        virtual void GetTaskByIDWithPolicyApplied2 (
						const std::wstring &taskId,
						TaskInfo& ti) = 0;

    /*!
      \brief ��������� ����� ������ � ������ ��������������� � ���������� �����.

		\param  TaskInfo&  		[in] ���������� � ������.

        \return ������������� ������ � ������ ��������������� � ���������� �����.
                �������� ������ Task Storage � ������������ ������� GetTaskId �
                �������� ������ (task->GetTaskId()).

    */
        virtual std::wstring AddTask2 ( const TaskInfo& ti ) = 0;

    /*!
      \brief ��������� ����� ������ � ������ ��������������� � ���������� �����.

        \param taskId			[in] ���������������� ������������� ������.
		\param  TaskInfo&  		[in] ���������� � ������.
    */
	virtual void AddTaskWithID2( const std::wstring &taskId,
								const TaskInfo& ti ) = 0;

    /*!
      \brief ��������� �������� ������ � ������ ���������������
             � ���������� ������������ ��������� �����.
			 �������� ���������� ������ Replace � SettingsStorage

		\param  TaskInfo&  		[out] ���������� � ������.

    */
        virtual void UpdateTask2 ( const TaskInfo& ti ) = 0;

    /*!
      \brief ��������� �������� ������ � ������ ���������������
             � ���������� ������������ ��������� �����.
			 �������� ���������� ������ Clear � SettingsStorage

		\param  TaskInfo&  		[out] ���������� � ������.

    */
        virtual void ReplaceTask ( const TaskInfo& ti ) = 0;

   /*!
      \brief ������� �������� ������ �� ������ ���������������
             � ���������� ������������ ��������� �����.

        \param taskId      [in]  ������������� ������ � Task Storage ��� ��������.

    */
        virtual void DeleteTask ( const std::wstring &taskId ) = 0;

     /*!
		\brief ���������� ��� ����� - ��������� ������

		\param taskId       [in]  ������������� ������ ��� ��������� ����������.
    */
		virtual std::wstring GetTaskFileName(const std::wstring &taskId) = 0;

	};
/*KLCSAK_END_PRIVATE*/
}

/*KLCSAK_BEGIN_PRIVATE*/
/*!
  \brief ������� proxy-������ ��� TasksStorage

	\param sServerObjectID			[in] ���������� ������������� ���������� ���������
    \param ppTasksStorage			[out] ��������� �� proxy-������
*/
KLCSKCA_DECL void KLPRTS_CreateTasksStorageProxy(const std::wstring& sServerObjectID,
											   const KLPRCI::ComponentId& cidLocalComponent,
											   const KLPRCI::ComponentId& cidComponent,
											   KLPRTS::TasksStorage** ppTasksStorage,
											   bool bCloseConnectionAtEnd = false);

/*!
  \brief ������� proxy-������ ��� TasksStorage2

	\param sServerObjectID			[in] ���������� ������������� ���������� ���������
    \param ppTasksStorage			[out] ��������� �� proxy-������
*/
KLCSKCA_DECL void KLPRTS_CreateTasksStorageProxy2( const std::wstring& sServerObjectID,
												   const KLPRCI::ComponentId& cidLocalComponent,
												   const KLPRCI::ComponentId& cidComponent,
												   KLPRTS::TasksStorage2** ppTasksStorage2,
												   bool bCloseConnectionAtEnd = false);

/*!
  \brief ������� ��������� proxy-������ ��� TasksStorage

	\param sServerObjectID			[in] ���������� ������������� ���������� ���������
    \param ppTasksStorage			[out] ��������� �� proxy-������
*/
KLCSKCA_DECL void KLPRTS_CreateLocalTasksStorageProxy(const std::wstring& sServerObjectID,
													  KLPRTS::TasksStorage** ppTasksStorage);

/*!
  \brief ������� ��������� proxy-������ ��� TasksStorage2

	\param sServerObjectID			[in] ���������� ������������� ���������� ���������
    \param ppTasksStorage			[out] ��������� �� proxy-������
*/
KLCSKCA_DECL void KLPRTS_CreateLocalTasksStorageProxy2(const std::wstring& sServerObjectID,
													   KLPRTS::TasksStorage2** ppTasksStorage);

/*!
  \brief ������� ������ TasksStorage

	\param sServerObjectID			[in] ���������� ������������� ���������� ���������
    \param sTasksStorageFilePath    [in] ������ ���� � �������� ��������� ������ �����(1 ������ - 1 ����)
	\param bLocalCopyOfServerStorage[in] true ���� ��������� ��������� ��� �����
	\param bAddAgentConnection		[in] ���������� ������������� ��������� ���������� � �������
	\param bDontPublishEvents		[in] ���� ���� ���������� ������ �� ��������� ������� � ����� ��������� �
										 �� ������������� �� ������� �� ��������� ������ ��������
*/
KLCSKCA_DECL void KLPRTS_CreateTasksStorageServer(const std::wstring& sServerObjectID,
												const KLPRCI::ComponentId& cidMaster,
												const std::wstring& sTasksStorageFilePath,
												const bool bLocalCopyOfServerStorage,
												const bool bAddAgentConnection = false,
												const bool bDontPublishEvents = false,
												const wchar_t *wstrHostName = NULL );

/*!
  \brief ������� ������ TasksStorage

    \param sServerObjectID			[in] ���������� ������������� ���������� ���������
*/
KLCSKCA_DECL void KLPRTS_DeleteTasksStorageServer(const std::wstring& sServerObjectID);

KLCSKCA_DECL void KLPRTS_SerializeTaskToParams(
            const std::wstring nUniqueTaskID,
            const KLPRCI::ComponentId &id,
            const std::wstring &taskName,
            const KLSCH::Task *task,
            const KLPAR::Params* parTaskParams,
            const KLPAR::Params* parTaskInfo,
            KLPAR::Params* parDestination,
            const std::wstring &wstrStartEvent = L"",
            const KLPRCI::ComponentId &cidStartEventFilter = KLPRCI::ComponentId(),
            const KLPAR::Params* parStartEventFilter = NULL );

KLCSKCA_DECL void KLPRTS_DeserializeTaskFromParams(
            KLPAR::Params* parSource,
            std::wstring& UniqueTaskID,
            KLPRCI::ComponentId& id,
            std::wstring& taskName,
            KLSCH::Task** task,
            KLPAR::Params** parTaskParams,
            KLPAR::Params** parTaskInfo,
            std::wstring * pwstrStartEvent = NULL,
            KLPRCI::ComponentId * pcidStartEventFilter = NULL,
            KLPAR::Params** parStartEventFilter = NULL );

KLCSKCA_DECL bool KLPRTS_IsLocalTask(const std::wstring &taskId);
/*KLCSAK_END_PRIVATE*/

#endif // KLPRTS_TASKSSTORAGE_H

