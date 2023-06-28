.PHONY: clean All Project_Title Project_Build

All: Project_Title Project_Build

Project_Title:
	@echo "----------Building project:[ bootloader - BuildSet ]----------"

Project_Build:
	@make -r -f bootloader.mk -j 12 -C  ./ 


clean:
	@echo "----------Cleaning project:[ bootloader - BuildSet ]----------"

