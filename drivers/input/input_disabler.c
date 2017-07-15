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
 * @ Advanced logging: checking if device was enabled/disabled
 *   and write to log (** of ** devices enabled/disabled).
 *
 * @ Smart enabling: enable device ONLY if he was disabled
 *   using THIS service.
 *
 */

void inputdisabler_set_touch(bool status)
{
    int cnt = 0;

    if (status)
    {
    /* Enable devices */
    pr_info("inputdisabler: %d devices was enabled", cnt);
    }
    else
    {
    /* Disable devices */
    pr_info("inputdisabler: %d devices was disabled", cnt);
    }

    return;
}

