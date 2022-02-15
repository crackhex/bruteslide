#ifndef SETTINGS
#define SETTINGS

#define DEVICE_ID 0

#define START_SEED 123456

#define PERM_REDS_PROB_MASK 63
#define PERM_REDS_SIZE_MASK 255
#define PERM_REDS_SIZE_OFFSET 128

#define MAX_CYCLES 250
#define OPTIMIZE_SHARES 10
#define OPTIMIZE_CYCLES 100
#define STITCHING_CYCLES 200
#define PRESS_WEIGHT 0.5f
#define FRAME_WEIGHT 100000.0f
#define PRESS_OFFSET 80.0f
#define PRESS_LIMIT 420
#define YAW_OFFSET 41428
#define EARLY_COLLECTION_BIAS 0.0

#define DIST_WEIGHT_1 25.0
#define DIST_WEIGHT_2 15.0
#define DIST_WEIGHT_3 15.0
#define DIST_WEIGHT_4 25.0
#define HSPD_WEIGHT_1 -2000.0
#define HSPD_WEIGHT_2 -2000.0
#define HSPD_WEIGHT_3 -2000.0
#define HSPD_WEIGHT_4 -1000.0
#define YAW_WEIGHT_1 0.005
#define YAW_WEIGHT_2 0.01
#define YAW_WEIGHT_3 0.01
#define YAW_WEIGHT_4 0.5
#define YAW_VEL_WEIGHT_1 0.1
#define YAW_VEL_WEIGHT_2 0.1
#define YAW_VEL_WEIGHT_3 0.1
#define YAW_VEL_WEIGHT_4 0.5
#define PITCH_WEIGHT_1 0.0
#define PITCH_WEIGHT_2 0.0
#define PITCH_WEIGHT_3 0.0
#define PITCH_WEIGHT_4 0.0

#define SEG1_BOUNDARY 130
#define SEG2_BOUNDARY 222
#define SEG3_BOUNDARY 308
#define SEG4_BOUNDARY 368

#define BPG 256
#define TPB 128
#define NUM_FRAMES 434
#define TRIG_VALUES 5120

#define TOTAL_THREADS BPG*TPB

#endif