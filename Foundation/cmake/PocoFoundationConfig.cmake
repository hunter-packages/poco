include("${CMAKE_CURRENT_LIST_DIR}/PocoFoundationTargets.cmake")

if (@POCO_UNBUNDLED@)
    if (@HUNTER_ENABLED@)
        find_package(ZLIB CONFIG REQUIRED)
    endif()
endif()
