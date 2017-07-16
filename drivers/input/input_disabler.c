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

/* Touch Buttons */

#ifdef CONFIG_KEYBOARD_ABOV_TOUCH_A3
    cntall++;
    if (abov_a3_set_status(status) == 0)
        cntsucc++;
#endif

/* Touch Screens */

    pr_info("inputdisabler: %d of %d devices was %s", cntsucc, cntall, status ? "enabled" : "disabled");

    return;
}

