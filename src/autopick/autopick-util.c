﻿#include "angband.h"
#include "autopick/autopick-util.h"

/*
 * 自動拾い/破壊設定のリストに関する変数 / List for auto-picker/destroyer entries
 */
int max_autopick = 0; /*!< 現在登録している自動拾い/破壊設定の数 */
int max_max_autopick = 0; /*!< 自動拾い/破壊設定の限界数 */
autopick_type *autopick_list = NULL; /*!< 自動拾い/破壊設定構造体のポインタ配列 */

/*
 * Automatically destroy an item if it is to be destroyed
 *
 * When always_pickup is 'yes', we disable auto-destroyer function of
 * auto-picker/destroyer, and do only easy-auto-destroyer.
 */
object_type autopick_last_destroyed_object;

/*
 * A function to delete entry
 */
void autopick_free_entry(autopick_type *entry)
{
	string_free(entry->name);
	string_free(entry->insc);
	entry->name = NULL;
	entry->insc = NULL;
}