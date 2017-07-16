/*
 * Copyright (c) 2017 The Lineage Project, Samsung MSM8916 Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/err.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>

#include <linux/input/input_disabler.h>

#ifdef CONFIG_KEYBOARD_ABOV_TOUCH_A3
#include <linux/input/abov_tk_a3.h>
#endif

#ifdef CONFIG_TOUCHSCREEN_ZINITIX_BT541
#include <linux/input/zinitix_bt541_tsp.h>
#endif

/*
 * InputDisabler is the touch-devices management service in Samsung MSM8916 kernels.
 *
 * This module is initialized by mdss_fb for primary panel.
 * When panel blank or unblank, touch devices will enabled or disabled.
 *
 */

/*
 * TODO:
 *
 * @ Smart enabling: enable device ONLY if he was disabled
 *   using THIS service.
 *
 * @ Make config for touchSCREEN devices disabling 
 *   for integrate with DT2W.
 */

void inputdisabler_set_touch(bool status)
{
    int cntsucc = 0;
    int cntall = 0;
    int ret = 0;

pr_info("inputdisabler: preparing to %s devices", status ? "enable" : "disable");

/* TouchKeys */

#ifdef CONFIG_KEYBOARD_ABOV_TOUCH_A3
    cntall++;
    ret = abov_a3_set_status(status);
    switch (ret)
    {
        case 0:
            cntsucc++;
            pr_info("inputdisabler: I: %s was successfilly %s", "ABOV_A3_TK", status ? "enabled" : "disabled");
            break;
        case -1:
            pr_info("inputdisabler: E: %s is already %s", "ABOV_A3_TK", status ? "enabled" : "disabled");
            break;
        case -2:
            pr_info("inputdisabler: E: %s is not ready", "ABOV_A3_TK");
            break;
        default:
            pr_info("inputdisabler: E: %s - Unknown Error", "ABOV_A3_TK");
    }
            
#endif

/* TouchScreens */

#ifdef CONFIG_TOUCHSCREEN_ZINITIX_BT541
    cntall++;
    ret = zinitix_bt541_set_status(status);
    switch (ret)
    {
        case 0:
            cntsucc++;
            pr_info("inputdisabler: I: %s was successfilly %s", "ZINITIX_BT541_TS", status ? "enabled" : "disabled");
            break;
        case -1:
            pr_info("inputdisabler: E: %s is already %s", "ZINITIX_BT541_TS", status ? "enabled" : "disabled");
            break;
        case -2:
            pr_info("inputdisabler: E: %s is not ready", "ZINITIX_BT541_TS");
            break;
        default:
            pr_info("inputdisabler: E: %s - Unknown Error", "ZINITIX_BT541_TS");
    }
#endif

    pr_info("inputdisabler: %d of %d devices was %s", cntsucc, cntall, status ? "enabled" : "disabled");

    return;
}

