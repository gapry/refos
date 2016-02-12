/* DO NOT EDIT MANUALLY!!!
   This file was generated by CIDL.

   Copyright 2014, NICTA

   This software may be distributed and modified according to the terms of
   the BSD 2-Clause license. Note that NO WARRANTY is provided.
   See "LICENSE_BSD2.txt" for details.

   @TAG(NICTA_BSD)
*/

#ifndef _RPC_INTERFACE_PROC_SERVER_H_
#define _RPC_INTERFACE_PROC_SERVER_H_

#include <refos-rpc/rpc.h>
#include <refos/refos.h>


/*! @file
    @brief Generated file for the proc interface. Please do NOT edit this file. */

#ifndef _RPC_PROC_LABEL_ENUMS_
#define _RPC_PROC_LABEL_ENUMS_
/*! @brief RPC syscall label enums for proc interface. */
enum rpc_proc_label_enum {
    RPC_PROC_LABEL_MIN = PROCSERV_METHODS_BASE,
    RPC_PROC_PING,
    RPC_PROC_NEW_ENDPOINT_INTERNAL,
    RPC_PROC_NEW_ASYNC_ENDPOINT_INTERNAL,
    RPC_PROC_WATCH_CLIENT,
    RPC_PROC_UNWATCH_CLIENT,
    RPC_PROC_CREATE_MEM_WINDOW_INTERNAL,
    RPC_PROC_RESIZE_MEM_WINDOW,
    RPC_PROC_DELETE_MEM_WINDOW,
    RPC_PROC_GET_MEM_WINDOW,
    RPC_PROC_GET_MEM_WINDOW_DSPACE,
    RPC_PROC_REGISTER_AS_PAGER,
    RPC_PROC_UNREGISTER_AS_PAGER,
    RPC_PROC_NOTIFICATION_BUFFER,
    RPC_PROC_WINDOW_MAP,
    RPC_PROC_WINDOW_UNMAP,
    RPC_PROC_WINDOW_GETID,
    RPC_PROC_SET_PARAMBUFFER,
    RPC_PROC_NEW_PROC,
    RPC_PROC_EXIT,
    RPC_PROC_CLONE_INTERNAL,
    RPC_PROC_NICE,
    RPC_PROC_GET_IRQ_HANDLER,
    RPC_PROC_LABEL_MAX
};
#endif

void server_proc_ping(void *rpc_userptr);
void reply_proc_ping(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_ping_handler(void *rpc_userptr) __attribute__((weak));

void server_proc_new_endpoint_internal(void *rpc_userptr);
void reply_proc_new_endpoint_internal(void *rpc_userptr, refos_err_t* rpc_errno, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_new_endpoint_internal_handler(void *rpc_userptr , refos_err_t* rpc_errno) __attribute__((weak));

void server_proc_new_async_endpoint_internal(void *rpc_userptr);
void reply_proc_new_async_endpoint_internal(void *rpc_userptr, refos_err_t* rpc_errno, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_new_async_endpoint_internal_handler(void *rpc_userptr , refos_err_t* rpc_errno) __attribute__((weak));

void server_proc_watch_client(void *rpc_userptr);
void reply_proc_watch_client(void *rpc_userptr, int32_t* rpc_deathID, refos_err_t rpc___ret__);
extern refos_err_t proc_watch_client_handler(void *rpc_userptr , seL4_CPtr rpc_liveness , seL4_CPtr rpc_deathEP , int32_t* rpc_deathID) __attribute__((weak));

void server_proc_unwatch_client(void *rpc_userptr);
void reply_proc_unwatch_client(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_unwatch_client_handler(void *rpc_userptr , seL4_CPtr rpc_liveness) __attribute__((weak));

void server_proc_create_mem_window_internal(void *rpc_userptr);
void reply_proc_create_mem_window_internal(void *rpc_userptr, refos_err_t* rpc_errno, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_create_mem_window_internal_handler(void *rpc_userptr , uint32_t rpc_vaddr , uint32_t rpc_size , uint32_t rpc_permissions , uint32_t rpc_flags , refos_err_t* rpc_errno) __attribute__((weak));

void server_proc_resize_mem_window(void *rpc_userptr);
void reply_proc_resize_mem_window(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_resize_mem_window_handler(void *rpc_userptr , seL4_CPtr rpc_window , uint32_t rpc_size) __attribute__((weak));

void server_proc_delete_mem_window(void *rpc_userptr);
void reply_proc_delete_mem_window(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_delete_mem_window_handler(void *rpc_userptr , seL4_CPtr rpc_window) __attribute__((weak));

void server_proc_get_mem_window(void *rpc_userptr);
void reply_proc_get_mem_window(void *rpc_userptr, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_get_mem_window_handler(void *rpc_userptr , uint32_t rpc_vaddr) __attribute__((weak));

void server_proc_get_mem_window_dspace(void *rpc_userptr);
void reply_proc_get_mem_window_dspace(void *rpc_userptr, refos_err_t* rpc_errno, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_get_mem_window_dspace_handler(void *rpc_userptr , seL4_CPtr rpc_window , refos_err_t* rpc_errno) __attribute__((weak));

void server_proc_register_as_pager(void *rpc_userptr);
void reply_proc_register_as_pager(void *rpc_userptr, seL4_Word* rpc_winID, refos_err_t rpc___ret__);
extern refos_err_t proc_register_as_pager_handler(void *rpc_userptr , seL4_CPtr rpc_window , seL4_CPtr rpc_faultNotifyEP , seL4_Word* rpc_winID) __attribute__((weak));

void server_proc_unregister_as_pager(void *rpc_userptr);
void reply_proc_unregister_as_pager(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_unregister_as_pager_handler(void *rpc_userptr , seL4_CPtr rpc_window) __attribute__((weak));

void server_proc_notification_buffer(void *rpc_userptr);
void reply_proc_notification_buffer(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_notification_buffer_handler(void *rpc_userptr , seL4_CPtr rpc_dataspace) __attribute__((weak));

void server_proc_window_map(void *rpc_userptr);
void reply_proc_window_map(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_window_map_handler(void *rpc_userptr , seL4_CPtr rpc_window , uint32_t rpc_windowOffset , uint32_t rpc_srcAddr) __attribute__((weak));

void server_proc_window_unmap(void *rpc_userptr);
void reply_proc_window_unmap(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_window_unmap_handler(void *rpc_userptr) __attribute__((weak));

void server_proc_window_getID(void *rpc_userptr);
void reply_proc_window_getID(void *rpc_userptr, int rpc___ret__);
extern int proc_window_getID_handler(void *rpc_userptr , seL4_CPtr rpc_window) __attribute__((weak));

void server_proc_set_parambuffer(void *rpc_userptr);
void reply_proc_set_parambuffer(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_set_parambuffer_handler(void *rpc_userptr , seL4_CPtr rpc_dataspace , uint32_t rpc_size) __attribute__((weak));

void server_proc_new_proc(void *rpc_userptr);
void reply_proc_new_proc(void *rpc_userptr, int32_t* rpc_status, refos_err_t rpc___ret__);
extern refos_err_t proc_new_proc_handler(void *rpc_userptr , char* rpc_name , char* rpc_params , bool rpc_block , int32_t rpc_priority , int32_t* rpc_status) __attribute__((weak));

void server_proc_exit(void *rpc_userptr);
void reply_proc_exit(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_exit_handler(void *rpc_userptr , int32_t rpc_status) __attribute__((weak));

void server_proc_clone_internal(void *rpc_userptr);
void reply_proc_clone_internal(void *rpc_userptr, refos_err_t* rpc_errno, int rpc___ret__);
extern int proc_clone_internal_handler(void *rpc_userptr , seL4_Word rpc_entryPoint , seL4_Word rpc_childStack , int rpc_flags , seL4_Word rpc_arg , refos_err_t* rpc_errno) __attribute__((weak));

void server_proc_nice(void *rpc_userptr);
void reply_proc_nice(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t proc_nice_handler(void *rpc_userptr , int rpc_threadID , int rpc_priority) __attribute__((weak));

void server_proc_get_irq_handler(void *rpc_userptr);
void reply_proc_get_irq_handler(void *rpc_userptr, seL4_CPtr rpc___ret__);
extern seL4_CPtr proc_get_irq_handler_handler(void *rpc_userptr , int rpc_irq) __attribute__((weak));

#endif /* _RPC_INTERFACE_PROC_SERVER_H_ */
