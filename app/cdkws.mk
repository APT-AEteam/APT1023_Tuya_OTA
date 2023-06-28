.PHONY: clean All Project_Title Project_Build

All: Project_Title Project_Build

Project_Title:
	@echo "----------Building project:[ app - BuildSet ]----------"

Project_Build:
	@make -r -f app.mk -j 12 -C  ./ 


clean:
	@echo "----------Cleaning project:[ app - BuildSet ]----------"

