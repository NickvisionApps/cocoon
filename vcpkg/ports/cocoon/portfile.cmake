vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO NickvisionApps/cocoon
    REF "${VERSION}"
    SHA512 01722c2a938adc22da3ec35222ceb8799eb536e695e66910b0962b4f969a16632540fd4fc6f2ee3386e603759d89cd616d002f0cfe61e1018164d2b5103e6648
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
