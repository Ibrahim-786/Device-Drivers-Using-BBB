cmd_/home/vm/Linux-DD-BBB/workspace/ldd/Device-Drivers-Using-BBB/005_pcd_platform_driver_dt/Module.symvers := sed 's/ko$$/o/' /home/vm/Linux-DD-BBB/workspace/ldd/Device-Drivers-Using-BBB/005_pcd_platform_driver_dt/modules.order | scripts/mod/modpost -m    -o /home/vm/Linux-DD-BBB/workspace/ldd/Device-Drivers-Using-BBB/005_pcd_platform_driver_dt/Module.symvers -e -i Module.symvers   -T -
