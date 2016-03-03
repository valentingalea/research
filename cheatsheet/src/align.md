##### Alignment

general: (last mod is for offset == 0 to work)

    new_offset = offset + padding = offset + (align - (offset mod align)) mod align

power-of-2:

    new_offset = (offset + align - 1) & ~(align - 1)
