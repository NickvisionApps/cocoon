vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO NickvisionApps/cocoon
    REF "${VERSION}"
    SHA512 2409f58f7adffa52dd0c040aae30e9a7c9a0800f3e7669bfb19ad8f53278ba277855906e38e15ff5ebeff1ca9e4add88118e68d16296baf28a950dc3622ebf6b
    HEAD_REF main
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DCOCOON_BUILD_EXAMPLES=OFF
        -DCOCOON_FORMAT=OFF
        -DCOCOON_REGENERATE=OFF
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(CONFIG_PATH lib/cmake/cocoon)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")

vcpkg_fixup_pkgconfig()

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")

file(COPY "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
