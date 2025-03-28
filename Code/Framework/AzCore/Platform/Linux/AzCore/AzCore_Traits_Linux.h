/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#define AZ_PLATFORM_LINUX

// Hardware traits ...
#define AZ_TRAIT_USE_PLATFORM_SIMD_SCALAR 0
#define AZ_TRAIT_USE_PLATFORM_SIMD_NEON 0
#define AZ_TRAIT_USE_PLATFORM_SIMD_SSE 1

// OS traits ...
#define AZ_TRAIT_OS_ALLOW_MULTICAST 1
#define AZ_TRAIT_OS_ALLOW_UNLIMITED_PATH_COMPONENT_LENGTH 1
#define AZ_TRAIT_OS_CAN_SET_FILES_WRITABLE 0
#define AZ_TRAIT_OS_DEFAULT_PAGE_SIZE (64 * 1024)
#define AZ_TRAIT_OS_DELETE_THROW noexcept
#define AZ_TRAIT_OS_DLL_EXPORT_CLANG __attribute__ ((visibility ("default")))
#define AZ_TRAIT_OS_DLL_IMPORT_CLANG __attribute__ ((visibility ("default")))
#define AZ_TRAIT_OS_ATTRIBUTE_MARK_USED UNUSED_TRAIT
#define AZ_TRAIT_OS_DYNAMIC_LIBRARY_EXTENSION ".so"
#define AZ_TRAIT_OS_DYNAMIC_LIBRARY_PREFIX "lib"
#define AZ_TRAIT_OS_EXECUTABLE_EXTENSION ""
#define AZ_TRAIT_OS_HAS_CRITICAL_SECTION_SPIN_COUNT 0
#define AZ_TRAIT_OS_HAS_DLL_SUPPORT 1
#define AZ_TRAIT_OS_HAS_MMAP 0
#define AZ_TRAIT_OS_HPHA_MEMORYBLOCKBYTESIZE (150 * 1024 * 1024)
#define AZ_TRAIT_OS_IS_HOST_OS_PLATFORM 1
#define AZ_TRAIT_OS_MEMORY_ALWAYS_NEW_DELETE_SUPPORT_ARRAYS 1
#define AZ_TRAIT_OS_MEMORY_INSTRUMENTATION 0
#define AZ_TRAIT_OS_MEMORY_MAX_ALLOCATOR_SIZE ((size_t)8 * 1024 * 1024 * 1024)
#define AZ_TRAIT_OS_PATH_SEPARATOR '/'
#define AZ_TRAIT_OS_PLATFORM_APPLE 0
#define AZ_TRAIT_OS_PLATFORM_NAME "Linux"
#define AZ_TRAIT_OS_PLATFORM_CFG_NAME "linux"
#define AZ_TRAIT_OS_PLATFORM_CODENAME AZ_TRAIT_OS_PLATFORM_NAME
#define AZ_TRAIT_OS_PLATFORM_CODENAME_LOWER "linux"
#define AZ_TRAIT_OS_STACK_FRAMES_PRINT 1
#define AZ_TRAIT_OS_STACK_FRAMES_TRACE 0
#define AZ_TRAIT_OS_STACK_FRAMES_VALID 1
#define AZ_TRAIT_OS_USE_WINDOWS_FILE_PATHS 0
#define AZ_TRAIT_OS_USE_WINDOWS_SET_EVENT 0
#define AZ_TRAIT_OS_USE_WINDOWS_SOCKETS 0
#define AZ_TRAIT_OS_USE_WINDOWS_THREADS 0
#define AZ_TRAIT_OS_USE_WINDOWS_MUTEX 0
#define AZ_TRAIT_SUPPORT_IPC 0

// Compiler traits ...
#define AZ_TRAIT_COMPILER_DEFINE_AZSWNPRINTF_AS_SWPRINTF 1
#define AZ_TRAIT_COMPILER_DEFINE_FS_ERRNO_TYPE 1
#define AZ_TRAIT_COMPILER_DEFINE_GETCURRENTPROCESSID 1
#define AZ_TRAIT_COMPILER_DEFINE_REFGUID 1
#define AZ_TRAIT_COMPILER_DEFINE_WCSICMP 0
#define AZ_TRAIT_COMPILER_INT64_T_IS_LONG 1
#define AZ_TRAIT_COMPILER_OPTIMIZE_MISSING_DEFAULT_SWITCH_CASE 1
#define AZ_TRAIT_COMPILER_PASS_4PLUS_VECTOR_PARAMETERS_BY_VALUE 1
#define AZ_TRAIT_COMPILER_THREAD_LOCAL __thread
#define AZ_TRAIT_COMPILER_USE_STATIC_STORAGE_FOR_NON_POD_STATICS 0
#define AZ_TRAIT_COMPILER_SUPPORT_CSIGNAL 1

// Misc ...
#define AZ_TRAIT_COMMAND_LINE_OPTION_PREFIX "-"
#define AZ_TRAIT_CTIME_GMTIME(tm_ptr, time_t_ptr) gmtime_r(time_t_ptr, tm_ptr)
#define AZ_TRAIT_CTIME_LOCALTIME(tm_ptr, time_t_ptr) localtime_r(time_t_ptr, tm_ptr)
#define AZ_TRAIT_CVARS_ENABLED_FOR_RELEASE_BUILDS 0
#define AZ_TRAIT_DENY_ASSETPROCESSOR_LOOPBACK 0
#define AZ_TRAIT_DOES_NOT_SUPPORT_FILE_DISK_OFFSET 0
#define AZ_TRAIT_HEAPSCHEMA_COMPILE_MALLINFO 1
#define AZ_TRAIT_IS_ABS_PATH_IF_COLON_FOUND_ANYWHERE 0
#define AZ_TRAIT_JSON_CLANG_IGNORE_UNKNOWN_WARNING 0
#define AZ_TRAIT_PERF_MEMORYBENCHMARK_IS_AVAILABLE 0
#define AZ_TRAIT_PUMP_SYSTEM_EVENTS_WHILE_LOADING 0
#define AZ_TRAIT_PUMP_SYSTEM_EVENTS_WHILE_LOADING_INTERVAL_MS 0
#define AZ_TRAIT_SCRIPT_RECORD_CALLSTACK_DEFAULT false
#define AZ_TRAIT_SEMAPHORE_HAS_NATIVE_MAX_COUNT 0
#define AZ_TRAIT_SET_JOB_PROCESSOR_ID 1
#define AZ_TRAIT_SET_STREAMER_COMPONENT_THREAD_AFFINITY_TO_USERTHREADS 0
#define AZ_TRAIT_SHOW_IGNORE_ALL_ASSERTS_OPTION 1
#define AZ_TRAIT_SKIP_CRYINTERLOCKED 0
#define AZ_TRAIT_SUPPORTS_MICROSOFT_PPL 0
#define AZ_TRAIT_SYSTEMFILE_INVALID_HANDLE ((SystemFile::FileHandleType) -1)
#define AZ_TRAIT_SYSTEMFILE_FSYNC_IS_DEFINED 1
#define AZ_TRAIT_SYSTEMFILE_UNIX_LIKE_PLATFORM_IS_WRITEABLE_DEFINED_ELSEWHERE 0
#define AZ_TRAIT_TEST_SUPPORT_DLOPEN 1
#define AZ_TRAIT_TEST_SUPPORT_LOADLIBRARY 0
#define AZ_TRAIT_TEST_SUPPORT_MODULE_LOADING 1
#define AZ_TRAIT_THREAD_AFFINITY_MASK_ALLTHREADS (-1)
#define AZ_TRAIT_THREAD_AFFINITY_MASK_MAINTHREAD AZ_TRAIT_THREAD_AFFINITY_MASK_ALLTHREADS
#define AZ_TRAIT_THREAD_AFFINITY_MASK_RENDERTHREAD AZ_TRAIT_THREAD_AFFINITY_MASK_ALLTHREADS
#define AZ_TRAIT_THREAD_AFFINITY_MASK_WORKERTHREADS AZ_TRAIT_THREAD_AFFINITY_MASK_ALLTHREADS
#define AZ_TRAIT_THREAD_AFFINITY_MASK_ASSET_PROCESSOR_CONNECTION_THREAD AZStd::clamp(4, 0, static_cast<int>(AZStd::thread::hardware_concurrency()) - 1)
#define AZ_TRAIT_THREAD_HARDWARE_CONCURRENCY_RETURN_VALUE static_cast<unsigned int>(sysconf(_SC_NPROCESSORS_ONLN));
#define AZ_TRAIT_UNITTEST_NON_PREALLOCATED_HPHA_TEST 0
#define AZ_TRAIT_USE_POSIX_STRERROR_R 1
#define AZ_TRAIT_USE_SECURE_CRT_FUNCTIONS 0
#define AZ_TRAIT_USE_WINDOWS_FILE_API 0
#define AZ_TRAIT_UUID_SUPPORTS_GUID_CONVERSION 1
#define AZ_TRAIT_USE_ERRNO_T_TYPEDEF 1

// wchar_t/char formatting
// Reason: https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160
// The Z type character, and the behavior of the c, C, s, and S type characters when they're used with the printf and wprintf functions,
// are Microsoft extensions. The ISO C standard uses c and s consistently for narrow characters and strings, and C and S for wide characters
// and strings, in all formatting functions.
#define AZ_TRAIT_FORMAT_STRING_PRINTF_CHAR "%c"
#define AZ_TRAIT_FORMAT_STRING_PRINTF_WCHAR "%C"
#define AZ_TRAIT_FORMAT_STRING_WPRINTF_CHAR "%c"
#define AZ_TRAIT_FORMAT_STRING_WPRINTF_WCHAR "%C"
#define AZ_TRAIT_FORMAT_STRING_PRINTF_STRING "%s"
#define AZ_TRAIT_FORMAT_STRING_PRINTF_WSTRING "%S"
#define AZ_TRAIT_FORMAT_STRING_WPRINTF_STRING "%s"
#define AZ_TRAIT_FORMAT_STRING_WPRINTF_WSTRING "%S"

// Legacy traits ...
#define AZ_TRAIT_LEGACY_CRYCOMMON_USE_WINDOWS_STUBS 1
#define AZ_TRAIT_LEGACY_CRYPAK_UNIX_LIKE_FILE_SYSTEM 1
#define AZ_TRAIT_LEGACY_CRYSYSTEM_DEFINE_DLLMAIN 0

