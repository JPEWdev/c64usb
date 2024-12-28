project('C64USB', 'c',
  default_options: [
    'buildtype=minsize',
    'b_lto=false',
    'b_staticpic=false',
    'cpp_rtti=false',
    'cpp_eh_=none',
    'werror=true',
    'warning_level=3',
    'c_std=c11',
  ]
)

assert(meson.is_cross_build(), 'Must be a cross build')

cpu_speed = meson.get_cross_property('cpu_speed')

add_project_arguments(
    '-fpack-struct',
    '-fshort-enums',
	'-funsigned-bitfields',
    '-funsigned-char',
    '-mmcu=' + host_machine.cpu(),
    '-DF_CPU=' + cpu_speed.to_string() + 'UL',
    language: 'c',
)

c_compiler = meson.get_compiler('c')

# Needed to work around a bug in newer versions of avr-gcc
if c_compiler.has_argument('--param=min-pagesize=0')
  add_project_arguments(
      '--param=min-pagesize=0',
      language: 'c',
  )
endif


add_project_link_arguments(
    '-mmcu=' + host_machine.cpu(),
    language: 'c',
)

program = executable('c64usb', [
    'src/keymaps.c',
    'src/main.c',
    'src/pin.c',
    'src/timer.c',
    'src/hid_report.c',
    'usbdrv/usbdrv.c',
    'usbdrv/usbdrvasm.S',
    'usbdrv/oddebug.c',
  ],
  include_directories: [
    include_directories('src', 'usbdrv'),
  ],
  link_args: [
    '-Wl,-Map,@0@/c64usb.map'.format(meson.current_build_dir()),
  ]
)

objdump = find_program('objdump')
disassembly = custom_target('disassembly',
  input: program,
  output: program.name() + '.asm',
  capture: true,
  command: [
    objdump,
    '-S', '@INPUT@',
  ]
)

alias_target('disassembly', disassembly)

objcopy = find_program('objcopy')

program_hex = custom_target('program-hex',
  input: program,
  output: program.name() + '.hex',
  command: [
    objcopy,
    '-j', '.text',
    '-j', '.data',
    '-O', 'ihex',
    '@INPUT@',
    '@OUTPUT@'
  ],
)

eeprom_hex = custom_target('eeprom-hex',
  input: program,
  output: program.name() + '.ee.hex',
  command: [
    objcopy,
    '-j', '.eeprom',
    '--change-section-lma', '.eeprom=0',
    '-O', 'ihex',
    '@INPUT@',
    '@OUTPUT@'
  ],
)

avrdude = find_program('avrdude')
avrdude_speed = meson.get_cross_property('avrdude_speed')
avrdude_programmer = get_option('avrdude_programmer')
avrdude_port = get_option('avrdude_port')

run_target('writeflash',
  depends: [program_hex, eeprom_hex],
  command: [
    avrdude,
    '-c', avrdude_programmer,
    '-P', avrdude_port,
    '-p', host_machine.cpu(),
    '-B', avrdude_speed,
    '-e',
    '-U', 'flash:w:' + program_hex.full_path(),
    '-U', 'eeprom:w:' + eeprom_hex.full_path(),
  ]
)

lfuse = meson.get_cross_property('lfuse')
hfuse = meson.get_cross_property('hfuse')
efuse = meson.get_cross_property('efuse', '')


python3 = find_program('python3')

custom_target('fuse-config',
  input: 'scripts/gen_fuses.py',
  output: 'fuses.txt',
  command: [
    python3,
    '@INPUT@',
    '--cpu', host_machine.cpu(),
    '--lfuse', lfuse,
    '--hfuse', hfuse,
    '--efuse', efuse,
    '--output', '@OUTPUT@'
  ]
)

# NOTE: We write the fuses at a slower speed because on
# new devices, the external clock is not configured yet so
# the high speed transfer fails
run_target('writefuses',
  command: [
    avrdude,
    '-c', avrdude_programmer,
    '-P', avrdude_port,
    '-p', host_machine.cpu(),
    '-B', '100',
	'-U', 'lfuse:w:' + lfuse + ':m',
	'-U', 'hfuse:w:' + hfuse + ':m',
  ] + (efuse != '' ? ['-U', 'efuse:w:' + efuse + ':m'] : []),
)

run_target('readfuses',
  command: [
    avrdude,
    '-c', avrdude_programmer,
    '-P', avrdude_port,
    '-p', host_machine.cpu(),
	'-B', avrdude_speed,
	'-U', 'lfuse:r:-:h',
	'-U', 'hfuse:r:-:h',
  ] + (efuse != '' ? ['-U', 'efuse:r:-:h'] : []),
)

run_target('readeeprom',
  command: [
    avrdude,
    '-c', avrdude_programmer,
    '-P', avrdude_port,
    '-p', host_machine.cpu(),
    '-B', avrdude_speed,
	'-U', 'eeprom:r:eeprom.hex:i'
  ]
)

run_target('readflash',
  command: [
    avrdude,
    '-c', avrdude_programmer,
    '-P', avrdude_port,
    '-p', host_machine.cpu(),
    '-B', avrdude_speed,
    '-U', 'flash:r:flash.hex:i'
  ]
)

avr_size = find_program('size')

run_target('stats',
  depends: [program],
  command: [
    avr_size,
    program,
  ]
)
