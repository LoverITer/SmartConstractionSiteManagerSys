package cn.edu.xust.iot.conf;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.builders.ApiInfoBuilder;
import springfox.documentation.builders.PathSelectors;
import springfox.documentation.builders.RequestHandlerSelectors;
import springfox.documentation.service.ApiInfo;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

/**
*@author HuangXin
*@since  2021/03/12 10:42
*/
@EnableSwagger2
@Configuration
public class SwaggerConfig {
	
	/**
	 * swagger2的配置文件，这里可以配置swagger2的一些基本的内容，比如扫描的包等等
	 * @return  Docket
	 */
	@Bean
    public Docket createRestApi(){
        return new Docket(DocumentationType.SWAGGER_2).apiInfo(apiInfo())
                .select()
                .apis(RequestHandlerSelectors.any())
                .paths(PathSelectors.any()).build();
    }

	/**
	 *   构建API文档的信息
	 * @return  ApiInfo
	 */
    private ApiInfo apiInfo(){
        return new ApiInfoBuilder()
                .title("Smart Constraction Site Monitor&Manager System API Doc")
                .description("This is a RESTful API document of Smart Constraction Site Monitor&Manager System.")
                .version("1.0")
                .build();
    }

}

