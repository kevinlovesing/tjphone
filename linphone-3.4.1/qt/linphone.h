#ifndef _LINPHONE_H_
#define _LINPHONE_H_

/*
linphone, gtk-glade interface.
Copyright (C) 2008  Simon MORLAT (simon.morlat@linphone.org)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifdef HAVE_CONFIG_H
#include "linphonecore_config.h"
#endif

#include "linphonecore.h"
#include <QString>


#ifdef USE_BUILDDATE_VERSION
#include "version_date.h"
#undef LINPHONE_VERSION
#define LINPHONE_VERSION LINPHONE_VERSION_DATE
#endif

extern LinphoneCoreVTable callback_vtable;
extern LinphoneCore *the_core;
extern bool auto_answer;

typedef int    gint;
typedef gint   gboolean;

/*linphonecore  callback api*/
static void linphone_qt_global_state_changed(LinphoneCore *lc, LinphoneGlobalState gstate, const char *message);
static void linphone_qt_registration_state_changed(LinphoneCore *lc, LinphoneProxyConfig *cfg, LinphoneRegistrationState rs, const char *msg);
static void linphone_qt_show(LinphoneCore *lc);
static void linphone_qt_notify_recv(LinphoneCore *lc, LinphoneCall *call, const char *from, const char *event);
static void linphone_qt_notify_presence_recv(LinphoneCore *lc, LinphoneFriend * fid);
static void linphone_qt_new_unknown_subscriber(LinphoneCore *lc, LinphoneFriend *lf, const char *url);
static void linphone_qt_auth_info_requested(LinphoneCore *lc, const char *realm, const char *username);
static void linphone_qt_display_status(LinphoneCore *lc, const char *status);
static void linphone_qt_display_message(LinphoneCore *lc, const char *msg);
static void linphone_qt_display_warning(LinphoneCore *lc, const char *warning);
static void linphone_qt_display_url(LinphoneCore *lc, const char *msg, const char *url);
static void linphone_qt_call_log_updated(LinphoneCore *lc, LinphoneCallLog *cl);
static void linphone_qt_refer_received(LinphoneCore *lc, const char  *refer_to);
static void linphone_qt_call_state_changed(LinphoneCore *lc, LinphoneCall *call, LinphoneCallState cs, const char *msg);

static void linphone_qt_dtmf_received(LinphoneCore *lc, LinphoneCall *call, int dtmf);
static void linphone_qt_text_received(LinphoneCore *lc, LinphoneChatRoom *room, const LinphoneAddress *from, const char *message);
static void linphone_qt_buddy_info_updated(LinphoneCore *lc, LinphoneFriend *lf);
/*linphonecore  callback api end*/


bool all_other_calls_paused(LinphoneCall *refcall, const MSList *calls);
void linphone_qt_auto_answer(LinphoneCall *call);
void linphone_qt_update_call_buttons(LinphoneCall *call);
void new_unknown_subscriber(LinphoneCore *lc, LinphoneFriend *lf, const char *url);
//GdkPixbuf * create_pixbuf(const gchar *filename);
//GdkPixbufAnimation *create_pixbuf_animation(const gchar *filename);
//void add_pixmap_directory(const gchar *directory);
//GtkWidget*create_pixmap(const gchar     *filename);
//GtkWidget *_qt_image_new_from_memory_at_scale(const void *data, gint len, gint w, gint h, gboolean preserve_ratio);
///GdkPixbuf *_gdk_pixbuf_new_from_memory_at_scale(const void *data, gint len, gint w, gint h, gboolean preserve_ratio);

//GtkWidget *linphone_qt_create_window(const char *window_name);
//GtkWidget *linphone_qt_get_widget(GtkWidget *window, const char *name);
//GtkWidget *linphone_qt_create_widget(const char *filename, const char *widget_name);

LinphoneCore *linphone_qt_get_core(void);
//GtkWidget *linphone_qt_get_main_window();
//void linphone_qt_display_something(GtkMessageType type,const gchar *message);
//G_MODULE_EXPORT void linphone_qt_start_call(GtkWidget *button);
void linphone_qt_call_terminated();
void linphone_qt_show_friends(void);
void linphone_qt_show_contact(LinphoneFriend *lf);
void linphone_qt_set_my_presence(LinphoneOnlineStatus ss);
//G_MODULE_EXPORT void linphone_qt_show_parameters(void);
void linphone_qt_load_identities(void);
void linphone_qt_create_chatroom(const char *with);
//void linphone_qt_call_log_update(GtkWidget *w);
void linphone_qt_create_log_window(void);
//G_MODULE_EXPORT void linphone_qt_log_show(void);
void linphone_qt_log_push(OrtpLogLevel lev, const char *fmt, va_list args);
void linphone_qt_destroy_log_window(void);
void linphone_qt_check_logs();
const char *linphone_qt_get_ui_config(const char *key, const char *def);
int linphone_qt_get_ui_config_int(const char *key, int def);
void linphone_qt_set_ui_config_int(const char *key , int val);
//void linphone_qt_visibility_set(const char *hiddens, const char *window_name, GtkWidget *w, gboolean show);

void linphone_qt_open_browser(const char *url);
//G_MODULE_EXPORT void linphone_qt_check_for_new_version(void);
const char *linphone_qt_get_lang(const char *config_file);
void linphone_qt_set_lang(const char *code);
SipSetupContext* linphone_qt_get_default_sip_setup_context(void);
//GtkWidget * linphone_qt_show_buddy_lookup_window(SipSetupContext *ctx);
//void linphone_qt_buddy_lookup_set_keyword(GtkWidget *w, const char *kw);
void * linphone_qt_wait(LinphoneCore *lc, void *ctx, LinphoneWaitingState ws, const char *purpose, float progress);

void linphone_qt_show_main_window();
void linphone_qt_show_directory_search(void);
QString get_peer_name(const LinphoneAddress *from);
/*functions controlling the different views*/
gboolean linphone_qt_use_in_call_view();
//LinphoneCall *linphone_qt_get_currently_displayed_call();
void linphone_qt_create_in_call_view(LinphoneCall *call);
void linphone_qt_in_call_view_set_calling(LinphoneCall *call);
void linphone_qt_in_call_view_set_in_call(LinphoneCall *call);
void linphone_qt_in_call_view_update_duration(LinphoneCall *call);
void linphone_qt_in_call_view_terminate(LinphoneCall *call, const char *error_msg);
void linphone_qt_in_call_view_set_incoming(LinphoneCall *call, bool with_pause);
void linphone_qt_in_call_view_set_paused(LinphoneCall *call);
void linphone_qt_enable_mute_button(LinphoneCall *call, bool sensitive);
void linphone_qt_enable_hold_button(LinphoneCall *call, bool sensitive, bool holdon);
void linphone_qt_enable_transfer_button(LinphoneCore *lc, bool value);

void text_received(LinphoneCore *lc, LinphoneChatRoom *room, const LinphoneAddress *from, const char *message);

void linphone_qt_show_status(const char *status);
void display_message(const char *msg);
void display_warning(const char *msg);
void in_call_timer();
void call_log_updated(LinphoneCore *lc, LinphoneCallLog *cl);
void auth_info_requested(LinphoneCore *lc, const char *realm, const char *username);
void linphone_qt_show_login_frame(LinphoneProxyConfig *cfg);
void linphone_qt_exit_login_frame(void);
void linphone_qt_set_ui_config(const char *key, const char *value);

#endif //_LINPHONE_H_