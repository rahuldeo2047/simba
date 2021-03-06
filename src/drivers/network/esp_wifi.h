/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2017, Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Simba project.
 */

#ifndef __DRIVERS_ESP_WIFI_H__
#define __DRIVERS_ESP_WIFI_H__

#include "simba.h"

/**
 * WiFi operational mode.
 */
enum esp_wifi_op_mode_t {
    esp_wifi_op_mode_null_t = 0,
    esp_wifi_op_mode_station_t,
    esp_wifi_op_mode_softap_t,
    esp_wifi_op_mode_station_softap_t,
    esp_wifi_op_mode_max_t
};

/**
 * Physical WiFi mode.
 */
enum esp_wifi_phy_mode_t {
    esp_wifi_phy_mode_11b_t = 1,
    esp_wifi_phy_mode_11g_t,
    esp_wifi_phy_mode_11n_t
};

/**
 * DHCP status.
 */
enum esp_wifi_dhcp_status_t {
    esp_wifi_dhcp_status_stopped_t = 0,
    esp_wifi_dhcp_status_running_t
};

/**
 * Initialize the Espressif WiFi module. This function must be called
 * before calling any other function in this module.
 *
 * The module will only be initialized once even if this function is
 * called multiple times.
 *
 * @return zero(0) or negative error code.
 */
int esp_wifi_module_init(void);

/**
  * Set the WiFi operating mode to None, Station, SoftAP or Station +
  * SoftAP. The default mode is SoftAP.
  *
  * @param[in] mode Operating mode to set.
  *
  * @return zero(0) or negative error code.
  */
int esp_wifi_set_op_mode(enum esp_wifi_op_mode_t mode);

/**
  * Get the current WiFi operating mode. The operating mode can be
  * None, Station, SoftAP, or Station + SoftAP.
  *
  * @return Current operating mode.
  */
enum esp_wifi_op_mode_t esp_wifi_get_op_mode(void);

/**
  * Set the WiFi physical mode (802.11b/g/n).
  *
  * The SoftAP only supports b/g.
  *
  * @param[in] mode Physical mode.
  *
  * @return zero(0) or negative error code.
  */
int esp_wifi_set_phy_mode(enum esp_wifi_phy_mode_t mode);

/**
  * Get the physical mode (802.11b/g/n).
  *
  * @return WiFi physical mode.
  */
enum esp_wifi_phy_mode_t esp_wifi_get_phy_mode(void);

/**
  * Print information about the WiFi.
  */
void esp_wifi_print(void *chout_p);

#endif
