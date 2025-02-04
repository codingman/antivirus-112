/*!
 * (C) 2002 "Kaspersky Lab"
 *
 * \file Errors.h
 * \author ����� �����������
 * \date 2002
 * \brief �������� ����� ������, ������������ ������� Scheduler.
 *
 */
/*KLCSAK_PUBLIC_HEADER*/


#ifndef KLSCH_ERRORS_H
#define KLSCH_ERRORS_H

#include "std/err/errintervals.h"

namespace KLSCH {


    //! ������������ ����� ������ ������ Scheduler. 
    //  ����� �� ������� ������ ����� ������� ���� �� ���� ������.
    enum Errors {
        ERR_NONE = KLSCHERRSTART+0, 
        ERR_NO_MORE_TASKS,	/*!< ����� ��� ����� �� ���������� */
        ERR_TASK_TIMEOUT,	/*!< ������ ����������� ����� ����������� ������� */
        ERR_ID_EXISTS,		/*!< ������ � ����� ��������������� ��� ���������� */
        ERR_NO_MEMORY,		/*!< ��� ������ ��� ��������� ������� */
        ERR_TIME_INTERVAL,	/*!< ����������� ����� �������� ������� */
        ERR_TASK_ID,		/*!< ������������ ������������� ������ */
		ERR_TASK_STATE,		/*!< ������������ ��������� ������ */
        ERR_NO_TASK_ID,		/*!< �������������� ������������� ������ */
        ERR_TASK_CLASS_ID,	/*!< ������������ ������������� ������ ������ */
        ERR_NO_TASK_CLASS_ID, /*!< �������������� ������������� ������ ������ */
        ERR_SCHEDULE,		/*!< �������� ���������� ��� ������� ������ */
		ERR_SCHEDULE_EXPIRED,	/*!< ������ ����� ������������ ���������� */
        ERR_CALLBACK,		/*!< ������� ����� callback ��� ������� ������ */
        ERR_READONLY,		/*!< ������ �������� �������������� ������, 
										��������� ������ ��� ������ */
		ERR_SUSPEND_MODE,	/*!< ����������� ���������� � ���������������� ��������� */
		ERR_SCHEDULER_STATE,/*!< ������������ ��������� ������������ */
		ERR_INVALID_OBJECT, /*!< ����������� ������������������ ������ */
		ERR_TEST	        /*!< ������ ������������ ���������� */
    }; 


}

#endif // KLSCH_ERRORS_H
