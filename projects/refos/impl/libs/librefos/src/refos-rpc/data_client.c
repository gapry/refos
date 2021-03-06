/* DO NOT EDIT MANUALLY!!!
   This file was generated by CIDL.

   Copyright 2014, NICTA

   This software may be distributed and modified according to the terms of
   the BSD 2-Clause license. Note that NO WARRANTY is provided.
   See "LICENSE_BSD2.txt" for details.

   @TAG(NICTA_BSD)
*/

#include <refos-rpc/rpc.h>
#include <refos-rpc/data_client.h>
#include <refos/refos.h>

#include <refos/vmlayout.h>

#include <sys/types.h>

#include <stdint.h>
#include <stdlib.h>

/*! @file
    @brief Generated file for the data interface. Please do NOT edit this file. */

seL4_CPtr data_open(seL4_CPtr session, char* name, int flags, int mode, int size, int* errno) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("data_open", RPC_DATA_OPEN);
    rpc_set_dest(session);
    rpc_push_str(name);
    rpc_push_uint(flags);
    rpc_push_uint(mode);
    rpc_push_uint(size);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errno, sizeof(int));
    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

refos_err_t data_close(seL4_CPtr session, seL4_CPtr dspace_fd) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_close", RPC_DATA_CLOSE);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

int data_read(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, byte* buf, uint32_t count) {
    int rpc__error_;
    int __ret__;
    memset(&__ret__, 0, sizeof(int));

    rpc_init("data_read", RPC_DATA_READ);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(offset);
    rpc_push_uint(count);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf_array(buf, sizeof(byte), count);
    __ret__ = (int) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

int data_write(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, byte* buf, uint32_t count) {
    int rpc__error_;
    int __ret__;
    memset(&__ret__, 0, sizeof(int));

    rpc_init("data_write", RPC_DATA_WRITE);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(offset);
    rpc_push_buf_array(buf, sizeof(byte), count);
    rpc_push_uint(count);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (int) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

int data_getc(seL4_CPtr session, seL4_CPtr dspace_fd, int block) {
    int rpc__error_;
    int __ret__;
    memset(&__ret__, 0, sizeof(int));

    rpc_init("data_getc", RPC_DATA_GETC);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(block);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (int) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

refos_err_t data_putc(seL4_CPtr session, seL4_CPtr dspace_fd, int c) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_putc", RPC_DATA_PUTC);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(c);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

off_t data_lseek(seL4_CPtr session, seL4_CPtr dspace_fd, off_t offset, int whence) {
    int rpc__error_;
    off_t __ret__;
    memset(&__ret__, 0, sizeof(off_t));

    rpc_init("data_lseek", RPC_DATA_LSEEK);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_buf(&offset, sizeof(off_t));
    rpc_push_uint(whence);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(off_t));
    rpc_release();
    return __ret__;
}

uint32_t data_get_size(seL4_CPtr session, seL4_CPtr dspace_fd) {
    int rpc__error_;
    uint32_t __ret__;
    memset(&__ret__, 0, sizeof(uint32_t));

    rpc_init("data_get_size", RPC_DATA_GET_SIZE);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (uint32_t) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

refos_err_t data_expand(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t size) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_expand", RPC_DATA_EXPAND);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(size);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_datamap(seL4_CPtr session, seL4_CPtr dspace_fd, seL4_CPtr memoryWindow, uint32_t offset) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_datamap", RPC_DATA_DATAMAP);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_cptr(memoryWindow);
    rpc_push_uint(offset);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_dataunmap(seL4_CPtr session, seL4_CPtr memoryWindow) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_dataunmap", RPC_DATA_DATAUNMAP);
    rpc_set_dest(session);
    rpc_push_cptr(memoryWindow);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_init_data(seL4_CPtr session, seL4_CPtr destDataspace, seL4_CPtr srcDataspace, uint32_t srcDataspaceOffset) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_init_data", RPC_DATA_INIT_DATA);
    rpc_set_dest(session);
    rpc_push_cptr(destDataspace);
    rpc_push_cptr(srcDataspace);
    rpc_push_uint(srcDataspaceOffset);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_have_data(seL4_CPtr session, seL4_CPtr dspace_fd, seL4_CPtr faultNotifyEP, uint32_t* dataID) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_have_data", RPC_DATA_HAVE_DATA);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_cptr(faultNotifyEP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(dataID, sizeof(uint32_t));
    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_unhave_data(seL4_CPtr session, seL4_CPtr dspace_fd) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_unhave_data", RPC_DATA_UNHAVE_DATA);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t data_provide_data_from_parambuffer(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, uint32_t contentSize) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("data_provide_data_from_parambuffer", RPC_DATA_PROVIDE_DATA_FROM_PARAMBUFFER);
    rpc_set_dest(session);
    rpc_push_cptr(dspace_fd);
    rpc_push_uint(offset);
    rpc_push_uint(contentSize);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}


