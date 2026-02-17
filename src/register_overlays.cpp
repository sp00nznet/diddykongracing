#include "librecomp/overlays.hpp"

// Include the generated overlay/section table
#include "recomp_overlays.inl"

void register_overlays() {
    recomp::overlays::overlay_section_table_data_t sections{};
    sections.code_sections = section_table;
    sections.num_code_sections = num_sections;
    sections.total_num_sections = num_sections;

    recomp::overlays::overlays_by_index_t overlays{};
    overlays.table = overlay_sections_by_index;
    overlays.len = sizeof(overlay_sections_by_index) / sizeof(overlay_sections_by_index[0]);

    recomp::overlays::register_overlays(sections, overlays);
}
