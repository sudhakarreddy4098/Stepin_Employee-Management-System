## Test Plan

## High Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P |	Actual Output | status |
| --- | --- | --- | --- | --- | --- |
| H_01 | Adding new employee details  | id,name | Record updated sucessfully | Record ipdated sucessfully | pass |
| H_02 | Delete existed  employee  record | id=? | id found | id found | pass | 
| H_03 | checking list records present in system| view records | list of records | list of records | pass |
| H_04 | Search for particular employee record in system  | enter employee id | Record found | Record found | pass |
| H_05 | List of employee from main branch | main branch | main branch | main branch | 
| H_06 | Login into the system | Password | Accepted |Accepted| pass |
| H_07 | Exit from the system | Exit | Exited | Exited | pass |

## Low Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P |	Actual Output | status |
| --- | --- | --- | --- | --- | --- |
| L_01 | Delete employee record not existed  | id | id not found | id not found | pass |
| L_02 | Login into the system | Password | Denied | Denied | pass | 
| L_03 | display employee details| employee details | employee not found | employee not found | pass |
