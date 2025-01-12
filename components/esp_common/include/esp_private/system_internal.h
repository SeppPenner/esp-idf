// Copyright 2018 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_system.h"

/**
 * @brief  Internal function to restart PRO and APP CPUs.
 *
 * @note This function should not be called from FreeRTOS applications.
 *       Use esp_restart instead.
 *
 * This is an internal function called by esp_restart. It is called directly
 * by the panic handler and brownout detector interrupt.
 */
void esp_restart_noos(void) __attribute__ ((noreturn));

/**
 * @brief  Internal function to set reset reason hint
 *
 * The hint is used do distinguish different reset reasons when software reset
 * is performed.
 *
 * The hint is stored in RTC store register, RTC_RESET_CAUSE_REG.
 *
 * @param hint  Desired esp_reset_reason_t value for the real reset reason
 */
void esp_reset_reason_set_hint(esp_reset_reason_t hint);

/**
 * @brief  Internal function to get the reset hint value
 * @return  - Reset hint value previously stored into RTC_RESET_CAUSE_REG using
 *          esp_reset_reason_set_hint function
 *          - ESP_RST_UNKNOWN if the value in RTC_RESET_CAUSE_REG is invalid
 */
esp_reset_reason_t esp_reset_reason_get_hint(void);

#ifdef __cplusplus
}
#endif
