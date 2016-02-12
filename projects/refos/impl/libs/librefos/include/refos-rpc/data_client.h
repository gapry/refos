/* DO NOT EDIT MANUALLY!!!
   This file was generated by CIDL.

   Copyright 2014, NICTA

   This software may be distributed and modified according to the terms of
   the BSD 2-Clause license. Note that NO WARRANTY is provided.
   See "LICENSE_BSD2.txt" for details.

   @TAG(NICTA_BSD)
*/

#ifndef _RPC_INTERFACE_DATA_CLIENT_H_
#define _RPC_INTERFACE_DATA_CLIENT_H_

#include <refos-rpc/rpc.h>
#include <refos/refos.h>

#include <refos/vmlayout.h>

#include <sys/types.h>


/*! @file
    @brief Generated file for the data interface. Please do NOT edit this file. */

#ifndef _RPC_DATA_LABEL_ENUMS_
#define _RPC_DATA_LABEL_ENUMS_
/*! @brief RPC syscall label enums for data interface. */
enum rpc_data_label_enum {
    RPC_DATA_LABEL_MIN = DATASERV_METHODS_BASE,
    RPC_DATA_OPEN,
    RPC_DATA_CLOSE,
    RPC_DATA_READ,
    RPC_DATA_WRITE,
    RPC_DATA_GETC,
    RPC_DATA_PUTC,
    RPC_DATA_LSEEK,
    RPC_DATA_GET_SIZE,
    RPC_DATA_EXPAND,
    RPC_DATA_DATAMAP,
    RPC_DATA_DATAUNMAP,
    RPC_DATA_INIT_DATA,
    RPC_DATA_HAVE_DATA,
    RPC_DATA_UNHAVE_DATA,
    RPC_DATA_PROVIDE_DATA_FROM_PARAMBUFFER,
    RPC_DATA_LABEL_MAX
};
#endif

/*! @brief Opens a new dataspace at the dataspace server.

   Opens a new dataspace at the dataspace server, which represents a series of bytes. Dataspace
   mapping methods such as data_datamap() and data_init_data() directly or indirectly maps the
   contents of this dataspace into a memory window, after which the contents can be read from /
   written to. Alternatively, data_read() or data_write() may be used to read / write straight
   into a dataspace. The concept of a dataspace in RefOS is similar to a file in UNIX; what
   this dataspace represents depends on the server that is implementing this interface. See
   \ref dataspace for more info.

   Loosely based on the UNIX open() syscall.

   @param session The client connection session to the dataspace server.  (No ownership)
   @param name The name of the dataspace to open.
   @param flags The read / write / create flags.
   @param mode The mode to create new file with, in the case that a new one is created.
   @param size The size of dataspace to open. Note that some data servers may ignore this.
   @param errno Output errno variable, in the case that an error occurs. (No ownership)
   @return Capability to the new dataspace. (Transfers ownership) */
seL4_CPtr data_open(seL4_CPtr session, char* name, int flags, int mode, int size, int* errno);

/*! @brief Close a dataspace.

   Close a dataspace that has previously been opened with data_open(), at the given dataspace
   server. Based loosely on the UNIX close() syscall.

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to close.
   @return ESUCCESS on success, refos_err_t error otherwise. */
refos_err_t data_close(seL4_CPtr session, seL4_CPtr dspace_fd);

/*! @brief Read from a dataspace into a buffer.

   Directly read from a dataspace. Note that the dataspace server may or may not support this.
   Contents are transferred directly over IPC; so this method of reading is slow and can't send
   more than what the IPC buffer can't handle. Based loosely on the UNIX read() syscall.

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to read from.
   @param offset The offset into the dataspace to start reading from.
   @param buf The buffer to read into.
   @param count The length of the given buffer.
   @return Number of bytes read if success, negative value if error. */
int data_read(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, byte* buf, uint32_t count);

/*! @brief Write to a dataspace.

   Directly write to a dataspace from IPC buffer. This methods requires no setup, but is slow
   and can't write more than what the IPC buffer can't store. Note that the dataspace server
   may or may not support this. Based loosely on the UNIX write() syscall.

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to write to.
   @param offset The offset into the dataspace to start writing to.
   @param buf The buffer to write from.
   @param count The length of the given buffer.
   @return Number of bytes written if success, negative value if error. */
int data_write(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, byte* buf, uint32_t count);

/*! @brief Read the next character from a dataspace. Based loosely on the cstdlib fgetc().

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to read from.
   @param block Whether to block.
   @return The next character in dataspace. If block is enabled, then when there is no more
   info to read, the data server blocks us until there is. Otherwise, -1 is returned. */
int data_getc(seL4_CPtr session, seL4_CPtr dspace_fd, int block);

/*! @brief Writes the next character to a dataspace. Based loosely on the cstdlib fputc().

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to write to.
   @param c The character value to write.
   @return ESUCCESS if success, refos_err_t error otherwise. */
refos_err_t data_putc(seL4_CPtr session, seL4_CPtr dspace_fd, int c);

/*! @brief Sets the current offset from beginning of file. Based loosely on the UNIX
   lseek() syscall.

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to lseek for.
   @param offset The offset to lseek with. What this means depends on the whence parameter.
   @param whence The whence parameter of lseek; simiular to the UNIX version:
   SEEK_SET will Directly set the offset to given offset in bytes,
   SEEK_CUR will set offset to current location plus offset bytes (ie. relative),
   SEEK_END will set the offset to the size of the file in bytes.
   @return Resulting offset if success, negative value if error. */
off_t data_lseek(seL4_CPtr session, seL4_CPtr dspace_fd, off_t offset, int whence);

/*! @brief Get the size of the dataspace.

   This provides a shortcut alternative to abusing data_lseek() with SEEK_END to get the file
   size of a dataspace. Note that some dataspaces may not support this, as sometimes the size
   of a dataspaces makes no sense (eg. serial input).

   @param session The client connection session to the dataspace server.  (No ownership)
   @param dspace_fd The dataspace to get size for.
   @return Dataspace size in bytes. */
uint32_t data_get_size(seL4_CPtr session, seL4_CPtr dspace_fd);

/*! @brief Expand a given dataspace in size.

   Resize and expand a given dataspace. Note that some dataspaces may not support this, as
   sometimes the size of a dataspaces makes no sense (eg. serial input).

   @param session The client connection session to the dataspace server. (No ownership)
   @param dspace_fd The dataspace to expand.
   @param size The new size to expand dataspace to. Must be larger or equal to the value
   returned by data_get_size().
   @return ESUCCESS if success, refos_err_t error otherwise. */
refos_err_t data_expand(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t size);

/*! @brief Map the contents of the data to the given memory window.

   Map the contents of the data to the given memory window, so that the contents of the
   dataspace may be read by reading the window. Effectively sets the dataspace server up to be
   the pager. Writing using this method is not implemented yet.
   
   @param session The established session cap to the dataspace server. (No ownership)
   @param dataspace_fd The cap to the dataspace server's opened dataspace.
   @param memoryWindow Cap to the memory window to map the dataspace contents into.
   @param offset The offset in bytes from the beginning of the dataspace.
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_datamap(seL4_CPtr session, seL4_CPtr dspace_fd, seL4_CPtr memoryWindow, uint32_t offset);

/*! @brief Unmap the contents of the data from the given memory window.

   @param session The client connection session to the dataspace server. (No ownership)
   @param memoryWindow Capability to window to unmap dataspace from. (No ownership)
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_dataunmap(seL4_CPtr session, seL4_CPtr memoryWindow);

/*! @brief Initialises another dataspace by the contents of given dataspace.

   Initialises another dataspace by the contents of a source dataspace. The source dataspace is
   where the content is, and must originate from the invoked dataserver. Whether the
   destination dataspace and the source dataspace coming from the same dataserver is supported
   is up to the dataserver implementation; the dataserver documentation should be referred to.

   @param session The established session cap to the dataspace server.
   @param destDataspace Another dataspace to be initialised with content from the srcDataspace.
   @param srcDataspace The dataserver's own dataspace, where the content is.
   @param srcDataspaceOffset The content offset into the source dataspace.
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_init_data(seL4_CPtr session, seL4_CPtr destDataspace, seL4_CPtr srcDataspace, uint32_t srcDataspaceOffset);

/*!@brief Tell another dataspace to content initialise its dataspace via this dataserver.

   The local dataspace server calls another remote dataspace server to have the remote
   dataspace initalised by the contents of the local dataspace.
   
   The local dataspace must book-keep the given dataID. The remote dataspace then will notify
   through the given endpoint asking for content initialisation, the dataID being given in the
   notification.
   
   @param session The established session cap to the remote dataspace server.
   @param dspace_fd The cap to the remote dataspace to be initialised with content.
   @param faultNotifyEP The async endpoint to ask for content initialisation with.
   @param dataID The remote endpoint's unique data ID number, used for notification.
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_have_data(seL4_CPtr session, seL4_CPtr dspace_fd, seL4_CPtr faultNotifyEP, uint32_t* dataID);

/*!@brief Tell dataserver to stop providing content initialise data for its dataspace.
   
   @param session The established session cap to the remote dataspace server.
   @param dspace_fd The cap to the remote dataspace to be initialised with content.
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_unhave_data(seL4_CPtr session, seL4_CPtr dspace_fd);

/*!@brief Reply to content initialisation notification with the data.

   Gives the content from the local dataserver to the remote dataserver, in response to the
   remote server's earlier notification asking for content. The content is assumed to be in
   the set up parameter buffer. This call implicitly requires a parameter buffer to be
   set up, and will return ENOPARAMBUFFER if one has not been set up. 
   
   Note that even though the notification from the dataserver asking for content uses dataID to
   identify which dataspace, the reply, for security reasons, gives the actual dataspace cap.
   The dataID may be used securely iff the dataserver implementation supports per-client dataID
   checking, and a version of this method with dataID instead of a cap may be added.
   
   @param session The established session cap to the remote dataspace server.
   @param dspace_fd The cap to the remote dataspace to provide the content for.
   @param offset The offset into the remote dataspace to provide content for.
   @param contentSize The size of the content. (May have maximum content size.)
   @return ESUCCESS if success, refos_error error code otherwise. */
refos_err_t data_provide_data_from_parambuffer(seL4_CPtr session, seL4_CPtr dspace_fd, uint32_t offset, uint32_t contentSize);

#endif /* _RPC_INTERFACE_DATA_CLIENT_H_ */

