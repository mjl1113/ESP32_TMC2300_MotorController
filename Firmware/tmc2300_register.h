#pragma once

#ifdef __cplusplus
extern "C" {
#endif


/* GENERAL CONFIGURATION REGISTERS*/
#define TMC2300_GCONF_RW               (0x00)
/*extcap (Reset default=0)
0: Operation without external capacitor on VCP.
1: External capacitor available. No switching delays
*/
#define TMC2300_GCONF_RW_EXTCAP_MASK   (0b10)
#define TMC2300_GCONF_RW_EXTCAP_SHIFT  (1)
/*shaft
1: Inverse stepper motor direction
*/
#define TMC2300_GCONF_RW_SHAFT_MASK   (0b1000)
#define TMC2300_GCONF_RW_SHAFT_SHIFT  (3)
/*diag_index
0: DIAG output normal
1: DIAG pin outputs index pulse flag instead
*/
#define TMC2300_GCONF_RW_DIAG_INDEX_MASK   (0b10000)
#define TMC2300_GCONF_RW_DIAG_INDEX_SHIFT  (4)
/*diag_step
0: DIAG output normal
1: DIAG output shows step pulses from internal pulse generator (toggle upon each step)
*/
#define TMC2300_GCONF_RW_DIAG_STEP_MASK    (0b100000)
#define TMC2300_GCONF_RW_DIAG_STEP_SHIFT   (5)
/*multistep_filt (Reset default=1)
0: No filtering of STEP pulses
1: Software pulse generator optimization enabled when fullstep frequency > 750Hz (roughly). TSTEP shows filtered step time values when active.
*/
#define TMC2300_GCONF_RW_MULTISTEP_FILT_MASK   (0b1000000)
#define TMC2300_GCONF_RW_MULTISTEP_FILT_SHIFT  (6)
/*test_mode
0: Normal operation
1: Enable analog test output on pin DIR IHOLD[1..0] selects the function of DIR: 0…1: T120, DAC
Attention: Not for user, set to 0 for normal operation!
*/
#define TMC2300_GCONF_RW_TEST_MODE_MASK    (0b10000000)
#define TMC2300_GCONF_RW_TEST_MODE_SHIFT   (7)

/* GENERAL STATUS REGISTER*/
#define TMC2300_GSTAT_RWC               (0x01)
/*reset
1: Reset detected
*/
#define TMC2300_GSTAT_RWC_RESET_MASK    (0b1)
#define TMC2300_GSTAT_RWC_RESET_SHIFT   (0)
/*drv_err
1: Driver error
*/
#define TMC2300_GSTAT_RWC_DRV_ERR_MASK  (0b10)
#define TMC2300_GSTAT_RWC_DRV_ERR_SHIFT  (1)
/*u3v5
Actual state of the supply voltage comparator. A
high value means that the voltage sinks below
3.5V. This flag is not latched and thus does not
need to be cleared
*/
#define TMC2300_GSTAT_RWC_U3V5_MASK    (0b100)
#define TMC2300_GSTAT_RWC_U3V5_SHIFT   (2)

/* INTERFACE COUNTER
This register becomes
incremented with each successful UART interface write
access. Read out to check the serial transmission for lost
data. Read accesses do not change the content. The
counter wraps around from 255 to 0
*/
#define TMC2300_IFCNT_R               (0x02)

/* SENDDELAY for read access (time until reply is sent):
0, 1: 8 bit times (Attention: Don’t use 0 or 1 in multinode systems)
2, 3: 3*8 bit times
4, 5: 5*8 bit times
6, 7: 7*8 bit times
8, 9: 9*8 bit times
10, 11: 11*8 bit times
12, 13: 13*8 bit times
14, 15: 15*8 bit times
*/
#define TMC2300_NODECONF_W           (0x03)

/* IO INPUT STATUS*/
#define TMC2300_IOIN_R                (0x06)
/*EN (1=enable driver)*/
#define TMC2300_IOIN_R_EN_MASK        (0b1)
#define TMC2300_IOIN_R_EN_SHIFT       (0)
/*NSTDBY (0=standby, 1=enable)*/
#define TMC2300_IOIN_R_NSTDBY_MASK    (0b10)
#define TMC2300_IOIN_R_NSTDBY_SHIFT   (1)
/*AD0*/
#define TMC2300_IOIN_R_AD0_MASK       (0b100)
#define TMC2300_IOIN_R_AD0_SHIFT      (2)
/*AD1*/
#define TMC2300_IOIN_R_AD1_MASK       (0b1000)
#define TMC2300_IOIN_R_AD1_SHIFT      (3)
/*DIAG*/
#define TMC2300_IOIN_R_DIAG_MASK      (0b10000)
#define TMC2300_IOIN_R_DIAG_SHIFT     (4)
/*STEPPER (1: UART interface on)*/
#define TMC2300_IOIN_R_STEPPER_MASK   (0b100000)
#define TMC2300_IOIN_R_STEPPER_SHIFT  (5)
/*PDN_UART input*/
#define TMC2300_IOIN_R_PDN_UART_MASK  (0b1000000)
#define TMC2300_IOIN_R_PDN_UART_SHIFT (6)
/*MODE input (0: UART controlled operation)*/
#define TMC2300_IOIN_R_MODE_MASK      (0b10000000)
#define TMC2300_IOIN_R_MODE_SHIFT     (7)
/*STEP*/
#define TMC2300_IOIN_R_STEP_MASK      (0b100000000)
#define TMC2300_IOIN_R_STEP_SHIFT     (8)
/*DIR*/
#define TMC2300_IOIN_R_DIR_MASK       (0b1000000000)
#define TMC2300_IOIN_R_DIR_SHIFT      (9)
/*COMP_A1A2 (1: during LS passive braking: A1 voltage > A2 voltage)*/
#define TMC2300_IOIN_R_COMP_A1A2_MASK (0b10000000000)
#define TMC2300_IOIN_R_COMP_A1A2_SHIFT (10)
/*COMP_B1B2 (1: during LS passive braking: B1 voltage > B2 voltage)*/
#define TMC2300_IOIN_R_COMP_B1B2_MASK (0b100000000000)
#define TMC2300_IOIN_R_COMP_B1B2_SHIFT (11)
/* VERSION: 0x40-first version of the IC*/
#define TMC2300_IOIN_R_VERSION_MASK   (0xFF000000)
#define TMC2300_IOIN_R_VERSION_SHIFT  (24)

/* VELOCITY DEPENDENT DRIVER FEATURE CONTROL REGISTER SET (0x10..0x1F)*/

/* DRIVER CURRENT CONTROL*/
#define TMC2300_IHOLD_IRUN_W          (0x10)
/*IHOLD (Reset default=8)
Standstill current (0-1/32 ... 31-32/32)
Setting IHOLD=0 allows to choose freewheeling or
coil short circuit (passive braking) for motor stand still.
*/
#define TMC2300_IHOLD_IRUN_W_IHOLD_MASK   (0x1F)
#define TMC2300_IHOLD_IRUN_W_IHOLD_SHIFT  (4)
/*IRUN (Reset default=31)
Motor run current (8-9/32 ... 31-32/32)
Working with values below 8 is not recommended.
Hint: Choose sense resistors in a way, that normal
IRUN is 16 to 31 for best performance.
*/
#define TMC2300_IHOLD_IRUN_W_IRUN_MASK    (0x1F00)
#define TMC2300_IHOLD_IRUN_W_IRUN_SHIFT   (8)
/*IHOLDDLAY (Reset default=1)
Controls the number of clock cycles for motor power
 down after standstill is detected (stst=1) and
TPOWERDOWN has expired. The smooth transition
avoids a motor jerk upon power down.
0: instant power down
1..15: Delay per current reduction step in multiple
of 2^18 clocks

IHOLD_IRUN_W (0x10) - 驱动电流控制寄存器：

- IHOLD (位4-0)：静止电流设置 (0-1/32 ... 31-32/32)
- IRUN (位12-8)：运行电流设置 (8-9/32 ... 31-32/32)
- IHOLDDLAY (位19-16)：电流下降延迟设置
*/
#define TMC2300_IHOLD_IRUN_W_IHOLDDLAY_MASK   (0xF0000)
#define TMC2300_IHOLD_IRUN_W_IHOLDDLAY_SHIFT  (16)

/* TPOWERDOWN (Reset default=20)
Sets the delay time from stand still (stst) detection to motor
current power down. Time range is about 0 to 5.6 seconds.
0..(2^8-1) * 2^18 t_clk
Attention: A minimum setting of 2 is required to allow
automatic tuning of StealthChop PWM OFFS_AUTO.

TPOWERDOWN_W (0x11) - 断电延迟寄存器：

- 控制从检测到静止状态到电机电流断电的延迟时间
*/
#define TMC2300_TPOWERDOWN_W          (0x11)

/* TSTEP
Actual measured time between two 1/256 microsteps derived
from the step input frequency in units of 1/fCLK. Measured value
is (2^20)-1 in case of overflow or stand still.
The TSTEP related threshold uses a hysteresis of 1/16 of the
compare value to compensate for jitter in the clock or the step
frequency. (Txxx*15/16)-1 is the lower compare value for each
TSTEP based comparison.
This means, that the lower switching velocity equals the
calculated setting, but the upper switching velocity is higher as
defined by the hysteresis setting.

TSTEP_R (0x12) - 步进时间寄存器：

- 测量两个1/256微步之间的实际时间，单位为1/fCLK
*/
#define TMC2300_TSTEP_R               (0x12)

/* VACTUAL
VACTUAL allows moving the motor by UART control.
It gives the motor velocity in +-(2^23-1) [steps / t]
Normal operation. Driver reacts to STEP input.
1=0: Motor moves with the velocity given by VACTUAL. Step
pulses can be monitored via DIAG output, using diag_step or
diag_index setting. The motor direction is controlled by the sign
of VACTUAL. Optionally, poll MSCNT at least each 511 steps
to keep track of the actual position by accumulating the
difference of the actual value to the previous value.

VACTUAL_W (0x22) - 速度控制寄存器：

- 通过UART控制电机速度，范围为+-(2^23-1) [steps / t]
*/
#define TMC2300_VACTUAL_W             (0x22)

/* COOLSTEP AND STALLGUARD CONTROL REGISTER SET (0x14, 0x40..0x42)*/

/* TCOOLTHRS
This is the lower threshold velocity for switching on smart
energy (CoolStep and StallGuard feature). (unsigned)
Set this parameter to disable CoolStep at low speeds, where it
cannot work reliably. The stall output signal becomes enabled
when exceeding this velocity.
TCOOLTHRS > TSTEP
- CoolStep is enabled
- Stall output on pin DIAG is enabled

TCOOLTHRS_W (0x14) - 冷却阈值寄存器：

- 控制智能能量功能（CoolStep和StallGuard）的启用阈值速度
- 当TCOOLTHRS > TSTEP时，启用CoolStep和DIAG引脚上的失速输出
*/
#define TMC2300_TCOOLTHRS_W           (0x14)

/* SGTHRS
Detection threshold for stall. The StallGuard value SG_VALUE
becames compared with this threshold.
A stall is signaled when:
SG_VALUE ≤ SGTHRS?

SGTHRS_W (0x40) - 失速检测阈值寄存器：

- 设置失速检测的阈值
- 当SG_VALUE ≤ SGTHRS时，触发失速信号
*/
#define TMC2300_SGTHRS_W              (0x40)

/* SGVALUE
StallGuard result. SG_RESULT becomes updated with each
fullstep, independent of TCOOLTHRS and SGTHRS. A higher value
signals a lower motor load and more torque headroom.
Intended for StealthChop mode only. Bits 9 and 0 will always
show 0. Scaling to 10 bit is for compatibility to StallGuard2.

SGVALUE_R (0x41) - 失速检测结果寄存器：

- 存储StallGuard的检测结果
- 数值越高表示电机负载越低，扭矩余量越大
- 仅适用于StealthChop模式
*/
#define TMC2300_SGVALUE_R             (0x41)
#define TMC2300_SGVALUE_R_MASK        (0x3FF)
#define TMC2300_SGVALUE_R_SHIFT       (1)
#define TMC2300_SGVALUE_R_SCALE_MASK  (0xFF)

/* COOLCONF - SMART ENERGY CONTROL COOLSTEP AND STALLGUARD

COOLCONF_W (0x42) - 冷却配置寄存器：

- 配置CoolStep的相关参数
- 详细配置请参考单独的表格
*/
#define TMC2300_COOLCONF_W            (0x42)
/*
semin 
minimum StallGuard value for smart current control and
smart current enable

If the StallGuard result falls below SEMIN*32, the motor
current becomes increased to reduce motor load angle.
%0000: smart current control coolStep off
%0001 … %1111: 1 … 15
*/
#define TMC2300_COOLCONF_W_SEMIN_MASK   (0b1111)
#define TMC2300_COOLCONF_W_SEMIN_SHIFT  (0)

/*seup1-0 
current up step width
Current increment steps per measured StallGuard value 
%00 … %11: 1, 2, 4, 8
*/
#define TMC2300_COOLCONF_W_SEUP_MASK   (0b1100000)
#define TMC2300_COOLCONF_W_SEUP_SHIFT  (5)

/*semax0-3 
StallGuard hysteresis value for smart current control
If the StallGuard result is equal to or above
(SEMIN+SEMAX+1)*32, the motor current becomes
decreased to save energy.
%0000 … %1111: 0 … 15
如果StallGuard结果等于或高于(SEMIN+SEMAX*13)，电机电流将减少以节省能量。
设置范围：0 ~ %1111 0 ~ 15
*/
#define TMC2300_COOLCONF_W_SEMAX_MASK  (0xF00)
#define TMC2300_COOLCONF_W_SEMAX_SHIFT (8)

/*sedn0-1 (电流下降步速)
%00: 每32个StallGuard值减少1步
%01: 每8个StallGuard值减少1步
%10: 每2个StallGuard值减少1步
%11: 每个StallGuard值减少1步
*/
#define TMC2300_COOLCONF_W_SEDN_MASK   (0x6000)
#define TMC2300_COOLCONF_W_SEDN_SHIFT  (13)

/*semimin (最低智能电流控制电流)
0: 设置为0
1: 当前设置(IRUN)的1/12 (需要IRUN > 10)
2: 当前设置(IRUN)的1/4 (需要IRUN ≥ 20)
*/
#define TMC2300_COOLCONF_W_SEIMIN_MASK   (0x8000)
#define TMC2300_COOLCONF_W_SEIMIN_SHIFT  (15)


/* MICROSTEPPING CONTROL REGISTER SET (0x60..0x6B) - 微步控制寄存器组 */
/* MSCNT - 微步计数器
Microstep counter. Indicates actual position in
the microstep table for CUR_A. CUR_B uses an
offset of 256 into the table. Reading out
MSCNT allows determination of the motor
position within the electrical wave

微步计数器。指示CUR_A在微步表中的实际位置。
CUR_B使用表中的256偏移。读取MSCNT可以确定电机在电波内的位置。
范围：0..1023

MSCNT_R (0x6A) - 微步计数器寄存器：

- 存储当前微步位置
- 用于确定电机在电气周期内的位置
*/
#define TMC2300_MSCNT_R               (0x6A)
#define TMC2300_MSCNT_R_MASK          (0x3FF)

/* DRIVER REGISTER SET (0x6C..0x7F) - 驱动器寄存器组 */

/* CHOPCONF - CHOPPER CONFIGURATION - 斩波器配置
斩波器和驱动器配置
复位默认值=0x13000001

CHOPCONF_RW (0x6C) - 斩波器配置寄存器：

- 配置斩波器参数
- 控制驱动器使能、微步分辨率等
*/
#define TMC2300_CHOPCONF_RW           (0x6C)
/*enabledrv (驱动器使能)
1: 启用驱动器 (默认: 1, 启用)
*/
#define TMC2300_CHOPCONF_RW_ENABLEDRV_MASK  (0x1)
#define TMC2300_CHOPCONF_RW_ENABLEDRV_SHIFT (0)
/*tbl1-0 (TBL空白时间选择)
设置比较器空白时间为16、24、32或40个时钟
提示：对于大多数应用，推荐使用%00或%01
(默认: %01)
*/
#define TMC2300_CHOPCONF_RW_TBL_MASK  (0x1800)
#define TMC2300_CHOPCONF_RW_TBL_SHIFT (15)
/*mres0-3 (微步分辨率)
原生256微步设置。
%0000: 256, 128, 64, 32, 16, 8, 4, 2, 全步
降低的微步分辨率 (UART模式下默认32)。
分辨率给出每个正弦四分之一波的微步条目数。
选择较低的微步分辨率时，驱动器会自动使用导致对称波的微步位置。
每个步进脉冲的微步数 = 2^MRES
*/
#define TMC2300_CHOPCONF_RW_MRES_MASK  (0xF000000)
#define TMC2300_CHOPCONF_RW_MRES_SHIFT (24)
/*intpol (插值到256微步)
1: 实际微步分辨率(MRES)被外推到256微步，以获得最平滑的电机操作。
*/
#define TMC2300_CHOPCONF_RW_INTPOL_MASK  (0x10000000)
#define TMC2300_CHOPCONF_RW_INTPOL_SHIFT (28)
/*dedge (启用双边沿步进脉冲)
1: 在每个步进边沿启用步进脉冲，以减少步进频率要求。此模式与步进滤波功能(multistep_filt)不兼容
*/
#define TMC2300_CHOPCONF_RW_DEDGE_MASK  (0x20000000)
#define TMC2300_CHOPCONF_RW_DEDGE_SHIFT (29)
/*diss2g (禁用对地短路保护)
1: 禁用对地短路保护
*/
#define TMC2300_CHOPCONF_RW_DISS2G_MASK  (0x40000000)
#define TMC2300_CHOPCONF_RW_DISS2G_SHIFT (30)
/*dss2vs (功能侧短路保护)
0: 低侧短路保护开启
1: 低侧短路保护开启
*/
#define TMC2300_CHOPCONF_RW_DSS2VS_MASK  (0x80000000)
#define TMC2300_CHOPCONF_RW_DSS2VS_SHIFT (31)

/* DRV_STATUS - 驱动器状态标志和电流水平回读

DRV_STATUS_R (0x6F) - 驱动器状态寄存器：

- 存储驱动器状态标志
- 提供电流水平回读
*/
#define TMC2300_DRV_STATUS_R           (0x6F)
/*stst (standstill indicator) - 静止状态指示器
This flag indicates motor stand still in each operation mode. This occurs 2^20 clocks after the last step pulse.
1: 电机静止
*/
#define TMC2300_DRV_STATUS_R_STST_MASK    (0x80000000)
#define TMC2300_DRV_STATUS_R_STST_SHIFT   (31)
/*CS_ACTUAL (actual motor current / smart energy current) - 实际电机电流/智能能量电流
Actual current control scaling, for monitoring the function of the automatic current scaling.
*/
#define TMC2300_DRV_STATUS_R_CSACTUAL_MASK  (0x1F0000)
#define TMC2300_DRV_STATUS_R_CSACTUAL_SHIFT (19)
/*t150 (150°C comparator) - 150°C比较器
1: Temperature threshold is exceeded, driver is off
1: 温度阈值超出，驱动器关闭
*/
#define TMC2300_DRV_STATUS_R_T150_MASK    (0x200)
#define TMC2300_DRV_STATUS_R_T150_SHIFT   (9)
/*t120 (120°C comparator) - 120°C比较器
1: Temperature pre-warning threshold is exceeded
1: 温度预警告阈值超出
*/
#define TMC2300_DRV_STATUS_R_T120_MASK    (0x100)
#define TMC2300_DRV_STATUS_R_T120_SHIFT   (8)
/*olb (open load indicator phase B) - 相位B开路负载指示器
1: Open load detected on phase B.
Hint: This is just an informative flag. The driver takes no action upon it. False detection may occur in fast motion, only.
1: 检测到相位B开路负载
*/
#define TMC2300_DRV_STATUS_R_OLB_MASK     (0x80)
#define TMC2300_DRV_STATUS_R_OLB_SHIFT    (7)
/*ola (open load indicator phase A) - 相位A开路负载指示器
1: Open load detected on phase A.
Hint: This is just an informative flag. The driver takes no action upon it. False detection may occur in fast motion, only.
1: 检测到相位A开路负载
*/
#define TMC2300_DRV_STATUS_R_OLA_MASK     (0x40)
#define TMC2300_DRV_STATUS_R_OLA_SHIFT    (6)
/*s2vsb (low side short indicator phase B) - 相位B低侧短路指示器
1: Short on low-side MOSFET detected on phase B. The driver becomes disabled. The flags stay active, until the driver is disabled by software (enabledrv=0) or by the ENN input. Flags are separate for both chopper modes.
1: 检测到相位B低侧MOSFET短路
*/
#define TMC2300_DRV_STATUS_R_S2VSB_MASK   (0x20)
#define TMC2300_DRV_STATUS_R_S2VSB_SHIFT  (5)
/*s2vsa (low side short indicator phase A) - 相位A低侧短路指示器
1: Short on low-side MOSFET detected on phase A. The driver becomes disabled. The flags stay active, until the driver is disabled by software (enabledrv=0) or by the ENN input. Flags are separate for both chopper modes.
1: 检测到相位A低侧MOSFET短路
*/
#define TMC2300_DRV_STATUS_R_S2VSA_MASK   (0x10)
#define TMC2300_DRV_STATUS_R_S2VSA_SHIFT  (4)
/*s2gb (short to ground indicator phase B) - 相位B对地短路指示器
1: Short to GND detected on phase B. The driver becomes disabled. The flags stay active, until the driver is disabled by software (enabledrv=0) or by the ENN input.
1: 检测到相位B对地短路
*/
#define TMC2300_DRV_STATUS_R_S2GB_MASK    (0x8)
#define TMC2300_DRV_STATUS_R_S2GB_SHIFT   (3)
/*s2ga (short to ground indicator phase A) - 相位A对地短路指示器
1: Short to GND detected on phase A. The driver becomes disabled. The flags stay active, until the driver is disabled by software (enabledrv=0) or by the ENN input.
1: 检测到相位A对地短路
*/
#define TMC2300_DRV_STATUS_R_S2GA_MASK    (0x4)
#define TMC2300_DRV_STATUS_R_S2GA_SHIFT   (2)
/*ot (overtemperature flag) - 过温标志
1: The overtemperature limit has been reached. Drivers become disabled until otpw is also cleared due to cooling down of the IC.
The overtemperature flag is common for both bridges.
1: 达到过温限制，驱动器关闭
*/
#define TMC2300_DRV_STATUS_R_OT_MASK      (0x2)
#define TMC2300_DRV_STATUS_R_OT_SHIFT     (1)
/*otpw (overtemperature pre-warning flag) - 过温预警告标志
1: The overtemperature pre-warning threshold is exceeded.
The overtemperature pre-warning flag is common for both bridges.
1: 过温预警告阈值超出
*/
#define TMC2300_DRV_STATUS_R_OTPW_MASK    (0x1)
#define TMC2300_DRV_STATUS_R_OTPW_SHIFT   (0)



/* PWMCONF - VOLTAGE MODE PWM STEALTHCHOP - 电压模式PWM StealthChop
StealthChop PWM斩波器配置
复位默认值=0xC40D1024

PWMCONF_RW (0x70) - PWM配置寄存器：

- 配置StealthChop PWM参数
- 控制自动缩放、梯度适应等
*/
#define TMC2300_PWMCONF_RW            (0x70)

/* User defined amplitude(offset)
User defined PWM amplitude offset (0-255) related to full
motor current (CS_ACTUAL=31) in stand still.
(Reset default=36)
When using automatic scaling (pwm_autoscale=1) the
value is used for initialization, only. The autoscale
function starts with PWM_SCALE_AUTO=PWM_OFS and
finds the required offset to yield the target current
automatically.
PWM_OFS = 0 will disable scaling down motor current
below a motor specific lower measurement threshold.
This setting should only be used under certain conditions,
i.e. when the power supply voltage can vary up and down
by a factor of two or more. It prevents the motor going
out of regulation, but it also prevents power down below
the regulation limit.
PWM_OFS > 0 allows automatic scaling to low PWM duty
cycles even below the lower regulation threshold. This
allows low (standstill) current settings based on the
actual (hold) current scale (register IHOLD_IRUN).

*/
#define TMC2300_PWMCONF_RW_PWMOFS_MASK  (0xFF)
#define TMC2300_PWMCONF_RW_PWMOFS_SHIFT (0)

/* User defined amplitude gradient
Velocity dependent gradient for PWM amplitude:
PWM_GRAD * 256 / TSTEP
This value is added to PWM_AMPL to compensate for the
velocity-dependent motor back-EMF.
(Reset default=16)
With automatic scaling (pwm_autoscale=1) the value is
used for first initialization, only. Set PWM_GRAD to the
application specific value (it can be read out from
PWM_GRAD_AUTO) to speed up the automatic tuning
process.
*/
#define TMC2300_PWMGRAD_RW_PWMOFS_MASK  (0xFF00)
#define TMC2300_PWMGRAD_RW_PWMOFS_SHIFT (8)

/* PWM frequency selection
%00: fPWM=2/1024 fCLK
%01: fPWM=2/683 fCLK
%10: fPWM=2/512 fCLK
%11: fPWM=2/410 fCLK
*/
#define TMC2300_PWMCONF_RW_PWMFREQ_MASK  (0x30000)
#define TMC2300_PWMCONF_RW_PWMFREQ_SHIFT (16)



/*pwm_autoscale (PWM自动幅度缩放)
0: 用户定义的固定前向PWM幅度。电流设置IRUN和IHOLD不由调节强制，而仅由PWM幅度强制。
产生的PWM幅度限制为0..255
PWM_OFS = (IRUN_ACTUAL-1) / 32
*/
#define TMC2300_PWMCONF_RW_PWM_AUTOSCALE_MASK  (0x40000)
#define TMC2300_PWMCONF_RW_PWM_AUTOSCALE_SHIFT (18)
/*pwm_autograd (PWM自动梯度适应)
0: PWM_GRAD的固定值
1: 自动调优 (仅在pwm_autoscale=1时)
PWM_GRAD_AUTO使用PWM_GRAD初始化，并在运动期间自动优化。
前提条件：
1. PWM_OFS_AUTO已自动初始化。这需要在IRUN下静止>130ms，以便a)通过等待>128个斩波器周期检测静止状态，并c)调节PWM_OFS_AUTO，使得
1 - PWM_SCALE_AUTO < 1
2. 电机运行且PWM_SCALE_SUM < 255且
PWM_SCALE_SUM < (IRUN+1)/32
4. 自动调优所需时间：IRUN/132
*/
#define TMC2300_PWMCONF_RW_PWM_AUTOGRAD_MASK  (0x80000)
#define TMC2300_PWMCONF_RW_PWM_AUTOGRAD_SHIFT (19)
/*freewheel0 (当电机电流设置为零时允许不同的静止选项)
%00: 正常操作 (当IHOLD=0时始终选择)
%01: 自由轮
%10: 使用LS驱动器短路线圈 (被动制动)
%11: 使用HS驱动器短路线圈 (被动制动)
*/
#define TMC2300_PWMCONF_RW_FREEWHEEL_MASK  (0x300000)
#define TMC2300_PWMCONF_RW_FREEWHEEL_SHIFT (20)
/*pwm_reg (调节环路梯度)
用户定义的每半波最大PWM幅度变化，当使用pwm_autoscale=1时(1..15)：
0: 0.5增量 (最慢调节)
1: 1增量
2: 1.5增量
3: 2增量 (默认)
...
8: 4增量
...
15: 7.5增量 (最快调节)
*/
#define TMC2300_PWMCONF_RW_PWMREG_MASK  (0xF000000)
#define TMC2300_PWMCONF_RW_PWMREG_SHIFT (24)
/*pwm_lim (PWM自动缩放幅度限制，当开启时)
定义禁用条件的上限。此值定义自动电流控制在重新开启时的位7至4的以下内容。
它可以设置为减少禁用条件后的电流峰值。
不限制PWM_GRAD或PWM_GRAD_AUTO偏移。
(默认: 12)
*/
#define TMC2300_PWMCONF_RW_PWMLIM_MASK  (0xF0000000)
#define TMC2300_PWMCONF_RW_PWMLIM_SHIFT (28)


/* PWM_SCALE - PWM缩放
这些值可用于监控自动PWM幅度缩放(255=最大电压)。
bit 7..0 PWM_SCALE_SUM:
实际PWM占空比。此值用于CUR_A和CUR_B读取值
CUR_A和CUR_B从正弦波表中读取。
bit 24..16 PWM_SCALE_AUTO:
9位有符号偏移，添加到计算的PWM占空比。
这是基于电流测量的自动幅度调节的结果。

PWM_SCALE_R (0x71) - PWM缩放寄存器：

- 监控自动PWM幅度缩放
- 提供实际PWM占空比和自动缩放偏移
*/
#define TMC2300_PWM_SCALE_R           (0x71)

/* PWM_SCALE_SUM:
Actual PWM duty cycle. This value is used for scaling the
values CUR_A and CUR_B read from the sine wave table.
*/
#define TMC2300_PWM_SCALE_R_PWMSUM_MASK       (0x000000FF)
#define TMC2300_PWM_SCALE_R_PWMSUM_SHIFT      (0)

/* PWM_SCALE_AUTO:
9 Bit signed offset added to the calculated PWM duty cycle. This is
the result of the automatic amplitude regulation based on current measurement. 
*/
#define TMC2300_PWM_SCALE_R_PWMAUTO_MASK    (0xFF0000)
#define TMC2300_PWM_SCALE_R_PWMAUTO_SHIFT   (16)



/* PWM_AUTO - PWM自动
可以读取自动生成的值，以确定PWM_GRAD和/或PWM_OFS的默认设置。
bit 7..0 PWM_OFS_AUTO:
自动确定的偏移值
0..255
bit 23..16 PWM_GRAD_AUTO:
自动确定的梯度值
0..255

PWM_AUTO_R (0x72) - PWM自动寄存器：

- 存储自动确定的PWM参数
- 用于确定PWM_GRAD和PWM_OFS的默认设置
*/
#define TMC2300_PWM_AUTO_R            (0x72)


#ifdef __cplusplus
}
#endif